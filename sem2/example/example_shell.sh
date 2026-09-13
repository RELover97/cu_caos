#!/usr/bin/env bash

# значение 123
var1=123
# пустое значение
var2=
# строка
var3="hello world"
# так нельзя - будет ошибка
# var4 = 123

# обращение к переменным
# вывод будет: $var1 hello world
echo '$var1' "$var2" "$var3" "$var_not_exist"

os_name=`uname -s`
arch_name=$(uname -m)
echo "OS is $os_name running on $arch_name"
# OS is Linux running on x86_64

# Функции

# 1. Только имя и скобки
very_important_function() {
   local local_var
   # реализация функции
}

# 2. Полный синтаксис 
function very_important_function() {
   global_var
   # реализация функции
}

# 3. Без скобок
function very_important_function {
   return 0
   # реализация функции
}

# вызов функции с двумя аргументами, и сохранением результата
value=$(very_important_function hello world)

# вывзов функции без сохранения возвращаемого результата
very_important_function hello world



# Перенаправление вывода



function f() {
   # вывод kek и списка аргументов
   echo "kek $*"
}

function g() {
   # замена e на E
   sed 's/e/E/g'
}

function h() {
   # замена d на первый аргумент функции
   echo $0
   sed "s/d/$1/g"
}

f first second third | g | h Meaow
# kEk first sEconMeaow thirMeaow

# команда wc -c подсчитвает количество байт
f | wc -c 
# 5



# f && (g || h)

if true
then
    echo "always printed"
   # эта часть всегда будет выполняться
fi

if false
then
    echo "never printed"
   # это не будет выполняться никогда
fi

while true
do
    break
   # не только простейшая, но и самая 
   # опасная конструкция, поскольку цикл
   # может никогда не завершиться
done

# 1. Итерация по элементам простого списка
for item in i love akos
do
   echo "$item"
done

# 2. Итерация по элемента генерируемого по маске списка файлов
for filename in *.txt
do
   echo "$filename might be plain text"
done

# чтение элементов списка из произвольной строки (разделители - подряд идущие пробельные символы)
for item in $(echo "i love    akos")
do
  echo "$item"
done

# i
# love
# akos

# переопределние символа разделителя (Internal Field Separator)
IFS=,
for item in $(echo "i,love,akos")
do
  echo "$item"
done

# i
# love
# akos


# Арифметика

a=5
b=3
c=$(($a+$b))
d=$(($a/$b))

echo "a = $a, b = $b, c = $c, d = $d"
# a = 5, b = 3, c = 8, d = 1

echo '(1+3)*2' | bc
# 8

# по умолчанию используется целочисленная арифметика,
# флаг -l подключает дополнительную функциональность
echo '(1+3)/2.5' | bc -l
# 1.60000000000000000000

# пример для bash - индексация с 0

array=(1 2 3 4 5 6)
array_size=${#array[@]}

# нестандартная форма for, доступная только в bash / zsh
for (( i=0; i<$array_size; i++ ))
do
    # удвоенное значение
    array[$i]=$(( ${array[$i]} * 2 ))
done

echo "${array[@]}"