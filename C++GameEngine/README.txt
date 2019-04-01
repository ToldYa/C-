Author: Emil Vesa
Pers.nr: 930715-0418 
Email: emil.vesa@gmail.com
Gör anspråk på betyget D

Spelet går ut på att skjuta på inkommande fiender.
Genom att röra på musen rör sig spelaren längst y-axeln.
Genom att klicka på 'x' tangenten skjuter spelaren en projektil som påverkas av simulerad gravitation.
När en fienden träffas ökas spelarens poäng med 100 och syns nära det övre vänstra hörnet.
Om fienden kolliderar med spelaren fortsätter spelet tills spelaren klickar på 'r' tangenten för att starta en ny omgång.

Sökvägar för BackgroundSprite och PlayerSprite defineras i main metoden genom att kalla på GameEngine engine.setBgPath(std::string) och setPlayerPath(std::string).
I main defineras även en önskad FPS genom engine.defineFPS(int).
Sökvägen för projektilens sprite ges i ProjectileSprite konstruktorn.
Sökvägen för fiendens sprite ges i EnemySprite konstruktorn.
Sökvägen för explosionens sprite ges i ExplosionSprite konstruktorn.
Sökvägen för TTF_Font ges i System konstruktorn.