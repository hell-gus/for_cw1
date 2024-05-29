//старый перестал работать
//эта версия создана гпт

void removeNotUpperSentence(Text* text){
    bool* toRemove = malloc(text->len * sizeof(bool)); // Массив флагов для удаления предложений
    if (toRemove == NULL) {
        // Обработка ошибки при выделении памяти
        perror("Failed to allocate memory");
        return;
    }

    // Инициализация массива флагов
    for (size_t i = 0; i < text->len; ++i) {
        toRemove[i] = false;
    }

    // Проверка предложений и установка флагов для удаления
    for (size_t i = 0; i < text->len; ++i) {
        Sentence* sentence = &text->sents[i];
        for (size_t j = 0; j < sentence->len; ++j) {
            Word* word = &sentence->words[j];
            if (!(word->len > 0 && iswupper(word->chars[0]))) {
                //wprintf(L"%c--%ls\n", word->chars[0], word->chars);
                toRemove[i] = true;
                break;
            }
        }
    }

    // Удаление предложений
    size_t shift = 0;
    for (size_t i = 0; i < text->len; ++i) {
        if (toRemove[i]) {
            removeSentence(i - shift, text);
            ++shift;
        }
    }

    free(toRemove); // Освобождение памяти
}

