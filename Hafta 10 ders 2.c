struct Dugum {
    int veri;
    int oncelik; 
    struct Dugum* sonraki;
};

int enYuksekOncelikSay(struct Dugum* head) {
    if (head == NULL) {
        return 0; 
    }

    int enYuksekOncelik = head->oncelik;
    int sayac = 0;
    
    struct Dugum* gecici = head;

    while (gecici != NULL && gecici->oncelik == enYuksekOncelik) {
        sayac++;
        gecici = gecici->sonraki;
    }

    return sayac;
}
