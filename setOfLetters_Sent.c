//ищет слова в тексте состояшие из набора букв
//из первого ПРЕДЛОЖЕНИЯ
void setOfLetters(Text* text) {
    int count_of_letters_in_first_sent = 0;

    // Подсчет количества букв в первом предложении
    for(int j = 0; j < text->sents[0].len; j++) {
        for(int h = 0; h < text->sents[0].words->len; h++) {
            count_of_letters_in_first_sent++;
        }
    }

    // Выделение памяти под буфер
    char* buffer = malloc(count_of_letters_in_first_sent * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Копирование букв в буфер
    int k = 0;
    for(int j = 0; j < text->sents[0].len; j++) {
        for(int h = 0; h < text->sents[0].words[j].len; h++) {
            buffer[k++] = text->sents[0].words[j].chars[h];
        }
    }

    // Поиск и вывод слов из последующих предложений
    for(int i = 1; i < text->len; i++) {
        for(int j = 0; j < text->sents[i].len; j++) {
            bool flag_words = true;
            for(int h = 0; h < text->sents[i].words[j].len; h++) {
                bool found = false;
                for(int k = 0; k < count_of_letters_in_first_sent; k++) {
                    if (text->sents[i].words[j].chars[h] == buffer[k]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    flag_words = false;
                    break;
                }
            }
            if (flag_words) {
                wprintf(L"%ls\n", text->sents[i].words[j].chars);
                //if(j < ...){
                //    wprintf(L"\n");
                //}
            }
        }
    }

    // Освобождение памяти
    free(buffer);
}
