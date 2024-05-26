void smile(Text* text)
{
    wchar_t sepSmile[] = L":=)";
    wchar_t smile[]=L"smile";                                                                                                                                 
    int i, j;
    for (i = 0; i < text->len; i++) {
        for (j = 0; j < text->sents[i].len; j++) {
            //wprintf(L"--%ls!!!\n", text->sents[i].words[j].chars); //с лишним слэшэном
            if (wcscmp(text->sents[i].words[j].chars, L"smile")==0 || wcscmp(text->sents[i].words[j].chars, L"Smile")==0) {
                wprintf(L"%ls", text->sents[i].words[j].chars);
                wprintf(L" :=)");
                wprintf(L"%lc", text->sents[i].words[j].sep);
                //j++;
                continue;
                }
            wprintf(L"%ls%lc", text->sents[i].words[j].chars, text->sents[i].words[j].sep);
            }
            //wprintf(L"\n");
        } 
    
    }
