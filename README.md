# Robotica - Tema 1: Sistem de încărcare a unui vehicul electric

În această temă am simulat o stație de încărcare pentru un vehicul electric, folosind mai multe LED-uri și butoane.

# Cerințe

Led-ul RGB reprezintă disponibilitatea stației. Dacă stația este liberă led-ul va fi verde, iar dacă stația este ocupată se va face roșu.

Led-urile simple reprezintă gradul de încărcare al bateriei, pe care îl vom simula printr-un loader progresiv (L1 = 25%, L2 = 50%, L3 = 75%, L4 = 100%). Loader-ul se încărca prin aprinderea succesivă a led-urilor, la un interval fix de 3s. LED-ul care semnifică procentul curent de încărcare va avea starea de clipire, LED-urile din urma lui fiind aprinse continuu, iar celelalte stinse.

Apăsarea scurtă a butonului de start va porni încărcarea. Apăsarea acestui buton în timpul încărcării nu va face nimic.

Apăsarea lungă a butonului de stop va opri încărcarea forțat și va reseta stația la starea liberă. Apăsarea acestui buton cat timp stația este liberă nu va face nimic. - TBD

# Flow

Starea stației este ‘liberă’. Loader-ul este stins, iar led-ul pentru disponibilitate este verde.

Se apasă butonul pentru start.

Led-ul pentru disponibilitate se face roșu, iar încărcarea începe prin aprinderea primului LED L1.

Led-ul 1 clipește timp de 3s, celelalte fiind stinse.

Dupa încărcarea primului procent de 25% led-ul rămâne aprins și se trece la următorul led, care va începe să clipească.

La finalizarea încărcării toate led-urile vor clipi simultan de 3 ori, iar apoi se vor stinge, pentru a semnaliza finalizarea procesului.

Led-ul pentru disponibilitate se face verde.

Dacă oricând de la pornirea încărcării până la finalizarea acesteia este apăsat lung (min 1s) butonul de stop, încărcarea se întrerupe prin animația de final (toate led-urile clipesc de 3 ori), iar led-ul pentru disponibilitate devine verde. - TBD

# Componentele utilizate

<img width="613" alt="Screenshot 2024-10-23 at 6 03 06 AM" src="https://github.com/user-attachments/assets/47f1d9e0-424b-4673-8d15-f847d8d0148f">

# Poze ale setup-ului fizic

![WhatsApp Image 2024-10-23 at 6 05 07 AM](https://github.com/user-attachments/assets/31128313-733d-47cb-b495-80329bf70e21)
![WhatsApp Image 2024-10-23 at 6 05 07 AM (1)](https://github.com/user-attachments/assets/a390ecd7-5a54-4b09-b18d-975abeea567e)
![WhatsApp Image 2024-10-23 at 6 05 06 AM](https://github.com/user-attachments/assets/3849c75c-8709-4572-ab43-7c45203c33ba)
![WhatsApp Image 2024-10-23 at 6 05 06 AM (2)](https://github.com/user-attachments/assets/4690869d-0fc7-475b-858a-111f0c036524)
![WhatsApp Image 2024-10-23 at 6 05 06 AM (1)](https://github.com/user-attachments/assets/3a9bc251-c850-45df-9ceb-35bb7fbe766c)

# Video cu funcționalitatea montajului fizic



https://github.com/user-attachments/assets/57d9664e-bbbb-4914-ab1c-bb7e92cd700e



# Schema electrică

![schema](https://github.com/user-attachments/assets/84df53fa-9348-4e8f-9b6b-b83a3cab20f8)
<img width="920" alt="Screenshot 2024-10-23 at 6 12 35 AM" src="https://github.com/user-attachments/assets/29089f1c-eb3d-4364-8cd5-b242e751590f">


