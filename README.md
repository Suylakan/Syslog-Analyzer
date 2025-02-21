# Syslog Analyzer

Bu proje, bir bağlı liste (linked list) kullanarak syslog dosyalarını okur, saklar ve analiz eder. Sistemdeki günlük olaylarını okumak ve belirli anahtar kelimeleri aramak için kullanılır.

## İçindekiler

- [Kullanım](#kullanım)
- [Fonksiyonlar](#fonksiyonlar)
- [Kurulum](#kurulum)

## Kullanım

1. Projeyi derleyin:
   ```sh
   gcc -o syslog_analyzer main.c
2. Programı Çalıştırın:
   ./syslog_analyzer
  syslog dosyasını okur ve ekrana bastırır

Fonksiyonlar
initList(LinkedList *list): Bağlı listeyi başlatır.

append(LinkedList *list, const char *data): Bağlı listeye yeni bir düğüm ekler.

display(const LinkedList *list): Bağlı listedeki düğümleri görüntüler.

freeList(LinkedList *list): Bağlı listedeki düğümleri temizler.

searchEvent(const LinkedList *list, const char *keyword): Bağlı listede anahtar kelimeyi arar.

## Kurulum
1. Kod dosyasını indirin veya klonlayın:
   git clone https://github.com/suylakan/syslog-analyzer.git
   
2. İlgili dizine gidin:
   cd syslog-analyzer
   
3. Projeyi derleyin:
   gcc -o syslog_analyzer main.c
