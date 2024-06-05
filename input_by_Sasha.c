Word readWord(){
    Word word;
    word.len = 0;
    word.chars = (wchar_t*) malloc(sizeof(wchar_t));

    wchar_t symbol;
    do{
        symbol = (wchar_t) getwchar();
    } while (symbol == L' ');

    while(true){
        if ((symbol == L' ') || (symbol == L'.') || (symbol == L',') || (symbol == L'\n') || (symbol == WEOF)){
            word.sep = symbol;
            word.chars[word.len] = L'\0';
            break;
        }
        word.chars[word.len++] = symbol;
        word.chars = (wchar_t*) realloc(word.chars, sizeof(wchar_t) * (word.len + 1));
        symbol = (wchar_t) getwchar();
    }

    return word;
}

Sentence readSentence(){
    Sentence sentence;
    sentence.len = 0;
    sentence.words = (Word*) malloc(sizeof(Word));
    Word new_word = readWord();
    while(true){
        sentence.words[sentence.len++] = new_word;
        if (new_word.sep == L'.' || new_word.sep == L'\n' || new_word.sep == WEOF) break;
        sentence.words = (Word*) realloc(sentence.words, sizeof(Word) * (sentence.len+1));
        new_word = readWord();
    }

    return sentence;
}


Text readText(){
    Text text;
    text.len = 0;
    text.sents = (Sentence*) malloc(sizeof(Sentence));
    Sentence new_sentence = readSentence();
    while(true){
        bool main_flag = true;
        for (unsigned i = 0; i < text.len; i++){
            bool second_flag = true;
            Sentence old_sentence = text.sents[i];
            if (new_sentence.len == old_sentence.len){
                for (unsigned j = 0; j < old_sentence.len; j++){
                    if((wcscasecmp(new_sentence.words[j].chars, old_sentence.words[j].chars) != 0) || (new_sentence.words[j].sep != old_sentence.words[j].sep)){
                        second_flag = false;
                        break;
                    }
                }
                if (second_flag){
                    main_flag = false;
                    break;
                }
            }
        }
        if (main_flag){
            text.sents[text.len++] = new_sentence;
            text.sents = (Sentence*) realloc(text.sents, sizeof(Sentence)*(text.len+1));
            if ((new_sentence.words[new_sentence.len -1].sep == L'\n') || (new_sentence.words[new_sentence.len - 1].sep == WEOF)) break;
        }
        new_sentence = readSentence();
    }

    return text;
}
