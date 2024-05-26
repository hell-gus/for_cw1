#include "input_and_output.h"

unsigned newlineCounter = 0;

Word readWord() {
    int size = MEMORY_STEP;
    int len = 0;
    wchar_t *chars = malloc(size * sizeof(wchar_t));
    wchar_t sep, symbol = L' ';
    int spaceCount = 0;
    
    while (symbol == L' ')
        symbol = getwchar();
    
    while ((!wcschr(WORD_SEP, symbol)) && (!wcschr(SENTENCE_SEP, symbol))) {
        if (symbol == L'\n') newlineCounter++;
        else newlineCounter = 0;
        if (newlineCounter == 2) break;
        
        if (symbol != L'\n') {
            if (len > 0 && chars[len - 1] == L'.') {
            } else {
                if (symbol == L' ') {
                    spaceCount++;
                    if (spaceCount == 1) {
                        chars[len++] = symbol;
                    }
                } else {
                    spaceCount = 0;
                    chars[len++] = symbol;
                }
            }
        } else if (len > 0 && chars[len - 1] != L'.') {
            chars[len++] = symbol;
        }
        
        if (len == size) {
            size += MEMORY_STEP;
            chars = (wchar_t *)realloc(chars, size * sizeof(wchar_t));
        }
        
        symbol = getwchar();
        
        if (symbol == L',') {
            if (len == size) {
                size += MEMORY_STEP;
                chars = (wchar_t *)realloc(chars, size * sizeof(wchar_t));
            }
            chars[len++] = symbol;
            symbol = getwchar();
            if (symbol == L' ') {
                chars[len++] = L' ';
                while (symbol == L' ') {
                    symbol = getwchar();
                }
            }
        }
    }
    
    chars[len] = L'\0';
    
    sep = symbol;
    
    return (Word) {chars, sep, len};
}

Sentence readSentence(){
    int size = MEMORY_STEP;
    int len = 0; // длина предложения
    int count=0;
    Word* words = (Word*)malloc(size*sizeof(Word)); // массив слов
    Word word; //  переменная слово

    do {
        word = readWord();
        memcpy(&words[len++], &word, sizeof(Word));//копирование слова в массив слов
        count++;
        if (len == size) {
            size += MEMORY_STEP;
            words = realloc(words, size * sizeof(Word));
        }

        if (newlineCounter==2){
            return (Sentence){words, len, count};// тут тоже добавил чтобы не было пропажи
        }

    } while (!wcschr(SENTENCE_SEP, word.sep));


    return (Sentence){words, len, count};
}

Text readText(){
    Text text;
    text.len=0;
    text.sents=NULL;
    Sentence new_sentence = readSentence();
    while (true) {
        bool main_flag = true;
        for (unsigned i = 0; i<text.len; i++){
            bool second_flag = true;
            Sentence old_sentence = text.sents[i];
            
            if (new_sentence.len == old_sentence.len){
                for (unsigned j=0; j<old_sentence.len; j++){
                    if ((wcscmp(new_sentence.words[j].chars, old_sentence.words[j].chars) !=0 ||
                    (new_sentence.words[j].sep!=old_sentence.words[j].sep))){
                        second_flag=false;
                        break;
                    }
                }
            if (second_flag){
                main_flag=false;
                break;
            }
            }
        }
    if (main_flag){
        text.sents=(Sentence*)realloc(text.sents, sizeof (Sentence)*(text.len+1));
        text.sents[text.len++]= new_sentence;

        if (new_sentence.words[new_sentence.len-1].sep ==L'\n' ) {
            break;
        }
    }
    new_sentence=readSentence();
    }
    return text;
}


void printText(Text text){
    for (int i = 0; i < text.len - 1; i++){
        for (int j = 0; j < text.sents[i].len; j++){
            wprintf(L"%ls%lc", text.sents[i].words[j].chars, text.sents[i].words[j].sep);
        }
        wprintf(L"\n");
    }

}

int findCopies(Word *word1, Word *word2) {
    int flag = 1;
    if (word1->len == word2->len) {
        for (size_t a = 0; a < word1->len; a++) {
            if (towlower(word1->chars[a]) != towlower(word2->chars[a])) {
                flag = 0;
                break;
            }
        }
    } else {
        flag = 0;
    }
    if (flag) {
        return 0;
    }
    return 1;
}

void format(Text *text) {
    
    for (size_t i = 0; i < text->len - 1; i++) {
        int duplicateFound = 0;

        for (size_t j = i + 1; j < text->len; j++) {
            
            if (!findCopies(&text->sents[i].words[0], &text->sents[j].words[0])) {
                
                if (duplicateFound) {
                    removeSentence(j, text);
                    j--;
                } else {
                    duplicateFound = 1; 
                }
            }
        }
    }
}

//first formating

void freeText(Text* text){
    for (size_t i = 0; i < text->len; i++)
        freeSentence(text->sents[i]);
    free(text->sents);
    text->len = 0;
}

void freeSentence(Sentence sent){ // функция освобождения памяти для одного предложения
    for(Word* word = sent.words; word < sent.words + sent.len; word++) // проходимся через каждое слово в предложении
        free(word->chars); // освобождение памяти для одного слова

    free(sent.words); // освобождение памяти, выделенной под массив слов в этом предложении
}

void removeSentence (int i, Text* text){
    freeSentence(text->sents[i]);
    memmove(text->sents+i, text->sents+i+1,(text->len-i-1)*sizeof(Sentence));
    text->len--;
}
