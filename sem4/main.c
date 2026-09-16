#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

enum EventType {
    EVENT_NONE = 0,
    EVENT_LOGIN,
    EVENT_ERROR,
    EVENT_PURCHASE
};


struct Event {
    uint64_t timestamp;
    enum EventType type;

    union {
        struct {
            char *username;
        } login;

        struct {
            int code;
            char *message;
        } error;

        struct {
            int product_id;
            int price;
        } purchase;
    } data;
};

void event_free(struct Event *event) {
    switch (event->type) {
        case EVENT_NONE:
            break;

        case EVENT_LOGIN:
            free(event->data.login.username);
            break;

        case EVENT_ERROR:
            free(event->data.error.message);
            break;

        case EVENT_PURCHASE:
            break;
    }

    *event = (struct Event){0};
}

void event_print(const struct Event *event) {
    printf("[%llu] ",
           (unsigned long long)event->timestamp);

    switch (event->type) {
        case EVENT_NONE:
            printf("NONE\n");
            break;

        case EVENT_LOGIN:
            printf(
                "LOGIN user=%s\n",
                event->data.login.username
            );
            break;

        case EVENT_ERROR:
            printf(
                "ERROR code=%d message=%s\n",
                event->data.error.code,
                event->data.error.message
            );
            break;

        case EVENT_PURCHASE:
            printf(
                "PURCHASE product=%d price=%d\n",
                event->data.purchase.product_id,
                event->data.purchase.price
            );
            break;
    }
}

int event_make_login(
    struct Event *event,
    uint64_t timestamp,
    const char *username
) {
    *event = (struct Event){
        .timestamp = timestamp,
        .type = EVENT_LOGIN
    };

    size_t length = strlen(username);

    event->data.login.username =
        malloc(length + 1);

    if (event->data.login.username == NULL) {
        *event = (struct Event){0};
        return 0;
    }

    memcpy(
        event->data.login.username,
        username,
        length + 1
    );

    return 1;
}

int event_make_error(
    struct Event *event,
    uint64_t timestamp,
    int code,
    const char *message
) {
    *event = (struct Event){
        .timestamp = timestamp,
        .type = EVENT_ERROR
    };

    event->data.error.code = code;

    size_t length = strlen(message);

    event->data.error.message =
        malloc(length + 1);

    if (event->data.error.message == NULL) {
        *event = (struct Event){0};
        return 0;
    }

    memcpy(
        event->data.error.message,
        message,
        length + 1
    );

    return 1;
}

void event_make_purchase(
    struct Event *event,
    uint64_t timestamp,
    int product_id,
    int price
) {
    *event = (struct Event){
        .timestamp = timestamp,
        .type = EVENT_PURCHASE,
        .data.purchase = {
            .product_id = product_id,
            .price = price
        }
    };
}

struct EventVector {
    struct Event *data;
    size_t size;
    size_t capacity;
};

void event_vector_init(struct EventVector *v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

int event_vector_reserve(
    struct EventVector *v,
    size_t new_capacity
) {
    if (new_capacity <= v->capacity) {
        return 1;
    }

    if (new_capacity > SIZE_MAX / sizeof(*v->data)) {
        return 0;
    }

    struct Event *tmp = realloc(
        v->data,
        new_capacity * sizeof(*v->data)
    );

    if (tmp == NULL) {
        return 0;
    }

    v->data = tmp;
    v->capacity = new_capacity;

    return 1;
}

int event_vector_push(
    struct EventVector *v,
    struct Event *event
) {
    if (v->size == v->capacity) {
        size_t new_capacity =
            v->capacity == 0
                ? 4
                : v->capacity * 2;

        if (!event_vector_reserve(v, new_capacity)) {
            return 0;
        }
    }

    v->data[v->size++] = *event;

    *event = (struct Event){0};

    return 1;
}

void event_vector_destroy(struct EventVector *v) {
    for (size_t i = 0; i < v->size; ++i) {
        event_free(&v->data[i]);
    }

    free(v->data);

    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}


int main(void) 
{
    struct EventVector lines;

    event_vector_init(&events);

    struct Event event;

    if (!event_make_login(&event, 100, "Alice")) {
        goto cleanup;
    }

    if (!event_vector_push(&events, &event)) {
        event_free(&event);
        goto cleanup;
    }

    if (!event_make_error(
            &event,
            200,
            42,
            "connection_lost"
        )) {
        goto cleanup;
    }

    if (!event_vector_push(&events, &event)) {
        event_free(&event);
        goto cleanup;
    }

    event_make_purchase(
        &event,
        300,
        123,
        1990
    );

    if (!event_vector_push(&events, &event)) {
        event_free(&event);
        goto cleanup;
    }

    for (size_t i = 0; i < events.size; ++i) {
        event_print(&events.data[i]);
    }

cleanup:
    event_vector_destroy(&events);

    return EXIT_SUCCESS;
}