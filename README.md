Задание 1. Реализация программы учёта времени

Что нужно сделать

Используя функцию получения текущего времени std::time, реализуйте простейший менеджер учёта времени.
Пользователь взаимодействует с программой с помощью команд:

    Команда begin начинает отслеживание новой задачи. После ввода этой команды пользователь должен ввести название 
задачи, над которой он планирует сейчас работать. Если уже была начата какая-то другая задача, предыдущая должна быть
автоматически завершена и начата новая.
    Команда end заканчивает отслеживание текущей задачи. Если текущей начатой задачи нет, то команда ничего не делает.
    Команда status выводит на экран информацию о всех законченных задачах и времени, которое было на них потрачено.
Также выводится название текущей выполняемой задачи, если таковая имеется.
    Команда exit выходит из программы.


Советы и рекомендации

Тип std::time_t принимайте за секунды и с помощью него рассчитывайте время в часах, которое было затрачено.