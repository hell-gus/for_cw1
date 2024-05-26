//пробелы добавляются после каждой запятой
Word readWord() {
    int size = MEMORY_STEP;
    int len = 0;
    wchar_t *chars = malloc(size * sizeof(wchar_t));
    wchar_t sep, symbol = L' ';
    
    while (symbol == L' ')
        symbol = getwchar();
    
    while ((!wcschr(WORD_SEP, symbol)) && (!wcschr(SENTENCE_SEP, symbol))) {
        if (symbol == L'\n') newlineCounter++;
        else newlineCounter = 0;
        if (newlineCounter == 2) break;
        
        if (symbol != L'\n') {
            if (len > 0 && chars[len - 1] == L'.') {
            } else {
                chars[len++] = symbol;
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
            if (len == size) {
                size += MEMORY_STEP;
                chars = (wchar_t *)realloc(chars, size * sizeof(wchar_t));
            }
            chars[len++] = L' ';
            symbol = getwchar();
        }
    }
    
    chars[len] = L'\0';
    
    sep = symbol;
    
    return (Word) {chars, sep, len};
}
