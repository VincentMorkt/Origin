// 7. Лотерея - довольно популярная игра. Карточка лотереи имеет нумерованные
// поля, из которых случайным образом выбирается определенное количество
// номеров. Напишите функцию Lotto(), принимающую два аргумента. Первым
// должно быть число номеров на карточке лотереи, а вторым - 
// количество случайным образом выбранных номеров. Функция должна возвращать объект
// vector<int>, содержащий отсортированные по порядку случайно выбранные
// номера. Эту функцию можно использовать, например, так:
// vector<int> winners;
// winners = Lotto(51, 6);
// Этот код присвоил бы объекту winners вектор, содержащий шесть случайным
// образом выбранных номеров в диапазоне от 1 до 51. Обратите внимание, что
// простого использования rand() не достаточно для решения этого упражнения,
// потому что она может генерировать дублированные значения. Совет: пусть
// функция создает вектор, который содержит все возможные значения, затем
// применяйте random_shuffle(), после чего используйте начало перетасованного 
// вектора для получения значений. Также напишите короткую программу для
// тестирования разработанной функции. 