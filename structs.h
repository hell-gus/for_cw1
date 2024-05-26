#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <time.h>
#include <wctype.h>
#include <stdbool.h>
#include <locale.h>


#define MEMORY_STEP 5 // Определение константы для шага выделения памяти
#define SENTENCE_SEP L"." // Определение константы для разделителя предложений
#define WORD_SEP L" ," // Определение константы для разделителей слов




#ifndef TEXT_STRUCT // Если не определена TEXT_STRUCT
#define TEXT_STRUCT // Определение TEXT_STRUCT

typedef struct Word{ // Определение структуры слова
    wchar_t * chars; // массив символов
    wchar_t sep; // символ-разделитель
    size_t len; // длина слова
    //size_t count;  //кол-во вхождений этого слова
    unsigned count_of_glasn_letters;
} Word;

typedef struct Sentence{ // Определение структуры предложения
    Word* words; // массив слов в предложении
    size_t len; // длина предложения
    size_t count;
} Sentence;

typedef struct Text{ // Определение структуры текста
    Sentence* sents; // массив предложений в тексте
    size_t len; // длина текста НИT. ЭТО КОЛИЧЕСТВО symbols
} Text;


#endif
