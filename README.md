# Nivel 2: Algoritmos y Estructuras de Datos

Push_swap: Algoritmos de ordenamiento y optimizacion.

En este proyecto ordenarás datos en un stack, con un conjunto limitado de instrucciones, y utilizando el menor número posible de acciones. Para tener éxito, deberás probar a utilizar varios tipos de algoritmos y elegir la solución más apropiada (de entre muchas posibles) para conseguir la ordenación optimizada de los datos.

## Introducción

Push_swap es un proyecto de algoritmia simple y muy efectivo: tienes que ordenar datos.

Tienes a tu disposición un conjunto de valores enteros, 2 stacks y un conjunto de instrucciones para manipular ambos stacks.

¿Cuál es tu objetivo? Escribir un programa en C llamado push_swap. El programa calculará y mostrará en la salida estándar el programa más pequeño, creado con las instrucciones de lenguaje Push swap, que ordene los números enteros recibidos como argumentos.

## Objetivos

Escribir un algoritmo de ordenamiento es un paso crucial en el viaje de un desarrollador. Normalmente es el primer encuentro con el concepto de complejidad.

Los algoritmos de ordenamiento y su complejidad suponen una parte importante de las preguntas realizadas durante las entrevistas laborales. Es posiblemente un buen momento para echar un vistazo a estos conceptos ya que tendrás que enfrentarte a ellos en algún momento de tu vida.

Los objetivos de aprendizaje de este proyecto son rigor, uso de C, y el uso de algoritmos básicos... haciendo especial hincapié en su complejidad

Ordenar valores es simple. Ordenarlos de forma rápida es menos simple, especialmente porque de una configuración de enteros a otra, la solución más eficiente para ordenar, puede diferir.

## 项目概述

Push_swap 是一个涉及栈排序的算法项目，目标是用最少的操作将一组随机整数排序。
我们有两个栈（A和B）和一系列限定的操作来操作这些栈。

### 主要目标

实现一个名为 push_swap 的程序，它能够用最少的指令将整数排序
	对于100个随机数，操作次数需少于700次
	对于500个随机数，操作次数需少于5500次

### 允许的操作

sa：交换栈A顶部的两个元素
sb：交换栈B顶部的两个元素
ss：同时执行sa和sb
pa：将栈B顶部元素移到栈A顶部
pb：将栈A顶部元素移到栈B顶部
ra：将栈A顶部元素移到栈A底部
rb：将栈B顶部元素移到栈B底部
rr：同时执行ra和rb
rra：将栈A底部元素移到栈A顶部
rrb：将栈B底部元素移到栈B顶部
rrr：同时执行rra和rrb
