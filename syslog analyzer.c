#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024  // Satır uzunluğu için sabit

// Düğüm yapısı
typedef struct Node {
    char data[MAX_LINE_LENGTH];  // Günlük verisi için karakter dizisi
    struct Node *next;           // Bir sonraki düğüme işaretçi
} Node;

// Bağlı liste yapısı
typedef struct LinkedList {
    Node *head;  // Listenin başını işaret eden işaretçi
} LinkedList;

// Fonksiyon Bildirimleri (Declarations)
void initList(LinkedList *list);
void append(LinkedList *list, const char *data);
void display(const LinkedList *list);
void freeList(LinkedList *list);
void searchEvent(const LinkedList *list, const char *keyword);

// Bağlı listeyi başlat
void initList(LinkedList *list) {
    list->head = NULL;  // Başlangıçta listenin başı NULL
}

// Yeni düğüm ekleme
void append(LinkedList *list, const char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));  // Yeni düğüm için hafızadan yer ayır
    strncpy(new_node->data, data, MAX_LINE_LENGTH); // Veriyi düğüme kopyala
    new_node->data[MAX_LINE_LENGTH - 1] = '\0';     // Karakter dizisinin sonuna null karakter ekle
    new_node->next = NULL;                          // Yeni düğümün next işaretçisini NULL yap

    if (list->head == NULL) {  // Eğer liste boşsa
        list->head = new_node; // Yeni düğüm liste başı olur
    } else {                   // Eğer liste boş değilse
        Node *last = list->head;
        while (last->next != NULL) {  // Listenin sonuna kadar git
            last = last->next;
        }
        last->next = new_node;  // Son düğümün next işaretçisi yeni düğümü işaret eder
    }
}

// Bağlı listeyi görüntüle
void display(const LinkedList *list) {
    Node *current = list->head;  // Listenin başından başlayarak
    while (current != NULL) {    // Son düğüme kadar devam et
        printf("%s\n", current->data); // Her düğümün verisini yazdır
        current = current->next;       // Bir sonraki düğüme geç
    }
}

// Bağlı listeyi temizle
void freeList(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->next;  // Sonraki düğümü kaydet
        free(current);               // Mevcut düğümü serbest bırak
        current = next;              // Bir sonraki düğüme geç
    }
    list->head = NULL;  // Listenin başını NULL yap
}

// Belirli bir olay arama
void searchEvent(const LinkedList *list, const char *keyword) {
    Node *current = list->head;
    while (current != NULL) {
        if (strstr(current->data, keyword)) { // Anahtar kelimeyi içeriyorsa
            printf("%s\n", current->data);    // Satırı yazdır
        }
        current = current->next;
    }
}

// Syslog dosyasını oku ve bağlı listeye ekle
int main() {
    LinkedList list;
    initList(&list);  // Bağlı listeyi başlat

    FILE *file = fopen("/var/log/syslog", "r");  // Syslog dosyasını aç
    if (file == NULL) {
        perror("Dosya açılamadı");  // Dosya açılamadıysa hata mesajı yazdır
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {    // Dosyadan satır satır oku
        line[strcspn(line, "\n")] = '\0';        // Satır sonu karakterini kaldır
        append(&list, line);                     // Satırı bağlı listeye ekle
    }

    fclose(file);  // Dosyayı kapat

    // Bağlı listeyi görüntüle
    display(&list);

    // Bağlı listeyi temizle
    freeList(&list);

    return 0;
}
