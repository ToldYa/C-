Author: Emil Vesa
Pers.nr: 930715-0418 
Email: emil.vesa@gmail.com
G�r anspr�k p� betyget D

Spelet g�r ut p� att skjuta p� inkommande fiender.
Genom att r�ra p� musen r�r sig spelaren l�ngst y-axeln.
Genom att klicka p� 'x' tangenten skjuter spelaren en projektil som p�verkas av simulerad gravitation.
N�r en fienden tr�ffas �kas spelarens po�ng med 100 och syns n�ra det �vre v�nstra h�rnet.
Om fienden kolliderar med spelaren forts�tter spelet tills spelaren klickar p� 'r' tangenten f�r att starta en ny omg�ng.

S�kv�gar f�r BackgroundSprite och PlayerSprite defineras i main metoden genom att kalla p� GameEngine engine.setBgPath(std::string) och setPlayerPath(std::string).
I main defineras �ven en �nskad FPS genom engine.defineFPS(int).
S�kv�gen f�r projektilens sprite ges i ProjectileSprite konstruktorn.
S�kv�gen f�r fiendens sprite ges i EnemySprite konstruktorn.
S�kv�gen f�r explosionens sprite ges i ExplosionSprite konstruktorn.
S�kv�gen f�r TTF_Font ges i System konstruktorn.