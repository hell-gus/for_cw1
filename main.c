#include "structs.h"
#include "funcs.h"
#include "input_and_output.h"
#include "extra_funcs.h"

int main(){
    setlocale(LC_ALL, ""); // Установка локали
    wprintf(L"Course work for option 5.3, created by Elena Guseva\n");

    Text text; // Объявление структуры текста
    
    wchar_t command = ' '; // Объявление переменной для выбора функции
    command = getwchar(); // Получение символа от пользователя из stdin
    getwchar(); // Получение символа новой строки
    switch(command){ // Выбор действия в зависимости от введенного символа пользователем
        case '0':
            text = readText(); // Чтение текста
            printText(text);
            format(&text);
            printText(text); // Вывод текста в stdout
            freeText(&text); // Освобождение памяти
            break;
        case '1':
            text = readText();
            format(&text);
            findMask(text);
            freeText(&text);
            break;
        case '2':
            text = readText();
            format(&text);
            removeNotUpperSentence(&text);
            printText(text);
            freeText(&text);
            break;
        case '3':
            text = readText();
            format(&text);
            sort_by_glasn_letters(text);
            printText(text);
            freeText(&text);
            break;
        case '4':
            text = readText();
            format(&text);
            povtor(text);
            printText(text);
            freeText(&text);
            break;
        case '5':
            wprintf(L"1)Для каждого предложения вывести строку образец, удовлетворяющую каждому слову в предложении. Строка условия содержит: символы, ? - 1 или больше любых символов, в начале и конце образца могут быть символы * - обозначающие 0 или больше символов. Например, для слов “Аристотель” и “Артишок”, строка образец будет иметь вид “Ар???о?*”.\n2)Удалить все предложения, в которых нет заглавных букв в начале слова.\n3)Отсортировать слова в предложении по количеству гласных букв в слове.\n4)Для каждого предложения вывести количество одинаковых слов в строке в формате “Количество одинаковых слов: <число>”, где <число> – кол-во одинаковых слов. Пример: “курсовая сдана, курсовая сдана сдана.” -> “Количество одинаковых слов: 5” (потому что 2 раза “курсовая” и 3 раза “сдана”). Слова сравнивать без учёта регистра\n");
            break;
        case '9':
            //wprintf(L"PA PA PA");
            text = readText();
            format(&text);
            //функция
            freeText(&text);
            break;
        default:
            wprintf(L"Неверный выбор действия, повторите попытку...\n");
            return 0;
    }
    return 0;
}
