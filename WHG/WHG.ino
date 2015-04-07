#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;

#define MAPHEADER 3
#define MAPTILESIZE 6
#define TILETOPX(x) x*MAPTILESIZE + 1
#define MAPFLAGCOIN 0xFD
#define MAPFLAGENEMY 0xFE
#define MAPFLAGEND 0xFF

// map header: winTile
//             mapWidth,mapHeight
//             map
//             playerX,playerY.....
//             MAPFLAGENEMY,speed,pointx,pointy,pointx,pointy,pointx,pointy.....
//             MAPFLAGEND
const byte gamemap1[] PROGMEM = {3,
                            18,6,
                            2,2,2,0,0,0,0,0,0,0,0,0,0,1,1,3,3,3,
                            2,2,2,0,1,1,1,1,1,1,1,1,1,1,0,3,3,3,
                            2,2,2,0,1,1,1,1,1,1,1,1,1,1,0,3,3,3,
                            2,2,2,0,1,1,1,1,1,1,1,1,1,1,0,3,3,3,
                            2,2,2,0,1,1,1,1,1,1,1,1,1,1,0,3,3,3,
                            2,2,2,1,1,0,0,0,0,0,0,0,0,0,0,3,3,3,
                            
                            TILETOPX(1),TILETOPX(2) + (MAPTILESIZE / 2),
                            
                            //Enemy Data
                            MAPFLAGENEMY,2,TILETOPX(13),TILETOPX(1),TILETOPX(4),TILETOPX(1),
                            MAPFLAGENEMY,2,TILETOPX(4),TILETOPX(2),TILETOPX(13),TILETOPX(2),
                            MAPFLAGENEMY,2,TILETOPX(13),TILETOPX(3),TILETOPX(4),TILETOPX(3),
                            MAPFLAGENEMY,2,TILETOPX(4),TILETOPX(4),TILETOPX(13),TILETOPX(4),
                            
                            MAPFLAGEND};

const byte gamemap2[] PROGMEM = {3,
                            18,6,
                            0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
                            0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
                            2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,
                            2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,
                            0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
                            0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
                            
                            TILETOPX(1),TILETOPX(2) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,2,TILETOPX(3),TILETOPX(0),TILETOPX(3),TILETOPX(5),
                            MAPFLAGENEMY,2,TILETOPX(5),TILETOPX(0),TILETOPX(5),TILETOPX(5),
                            MAPFLAGENEMY,2,TILETOPX(7),TILETOPX(0),TILETOPX(7),TILETOPX(5),
                            MAPFLAGENEMY,2,TILETOPX(9),TILETOPX(0),TILETOPX(9),TILETOPX(5),
                            MAPFLAGENEMY,2,TILETOPX(11),TILETOPX(0),TILETOPX(11),TILETOPX(5),
                            MAPFLAGENEMY,2,TILETOPX(13),TILETOPX(0),TILETOPX(13),TILETOPX(5),
                            MAPFLAGENEMY,2,TILETOPX(4),TILETOPX(5),TILETOPX(4),TILETOPX(0),
                            MAPFLAGENEMY,2,TILETOPX(6),TILETOPX(5),TILETOPX(6),TILETOPX(0),
                            MAPFLAGENEMY,2,TILETOPX(8),TILETOPX(5),TILETOPX(8),TILETOPX(0),
                            MAPFLAGENEMY,2,TILETOPX(10),TILETOPX(5),TILETOPX(10),TILETOPX(0),
                            MAPFLAGENEMY,2,TILETOPX(12),TILETOPX(5),TILETOPX(12),TILETOPX(0),
                            MAPFLAGENEMY,2,TILETOPX(14),TILETOPX(5),TILETOPX(14),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX(8) + (MAPTILESIZE / 2),TILETOPX(2) + (MAPTILESIZE / 2),
                            MAPFLAGEND};

const byte gamemap3[] PROGMEM = {2,
                            4,5,
                            1,0,0,0,
                            1,1,1,1,
                            1,2,2,1,
                            1,2,2,1,
                            1,1,1,1,
                            
                            TILETOPX(1) + (MAPTILESIZE / 2),TILETOPX(2) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,2,                          TILETOPX(0),TILETOPX(1),TILETOPX(3),TILETOPX(1),TILETOPX(3),TILETOPX(4),TILETOPX(0),TILETOPX(4),
                            MAPFLAGENEMY,2,TILETOPX(1),TILETOPX(1),  TILETOPX(3),TILETOPX(1),TILETOPX(3),TILETOPX(4),TILETOPX(0),TILETOPX(4),TILETOPX(0),TILETOPX(1),
                            MAPFLAGENEMY,2,TILETOPX(2)-2,TILETOPX(1),TILETOPX(3),TILETOPX(1),TILETOPX(3),TILETOPX(4),TILETOPX(0),TILETOPX(4),TILETOPX(0),TILETOPX(1),
                            
                            MAPFLAGENEMY,2,TILETOPX(3),TILETOPX(2),TILETOPX(3),TILETOPX(4),TILETOPX(0),TILETOPX(4),TILETOPX(0),TILETOPX(1),TILETOPX(3),TILETOPX(1),
                            MAPFLAGENEMY,2,TILETOPX(3),TILETOPX(3),TILETOPX(3),TILETOPX(4),TILETOPX(0),TILETOPX(4),TILETOPX(0),TILETOPX(1),TILETOPX(3),TILETOPX(1),
                            MAPFLAGENEMY,2,                        TILETOPX(3),TILETOPX(4),TILETOPX(0),TILETOPX(4),TILETOPX(0),TILETOPX(1),TILETOPX(3),TILETOPX(1),
                            
                            MAPFLAGENEMY,2,TILETOPX(2),TILETOPX(4),TILETOPX(0),TILETOPX(4),TILETOPX(0),TILETOPX(1),TILETOPX(3),TILETOPX(1),TILETOPX(3),TILETOPX(4),
                            MAPFLAGENEMY,2,TILETOPX(1),TILETOPX(4),TILETOPX(0),TILETOPX(4),TILETOPX(0),TILETOPX(1),TILETOPX(3),TILETOPX(1),TILETOPX(3),TILETOPX(4),
                            MAPFLAGENEMY,2,                        TILETOPX(0),TILETOPX(4),TILETOPX(0),TILETOPX(1),TILETOPX(3),TILETOPX(1),TILETOPX(3),TILETOPX(4),
                            
                            MAPFLAGENEMY,2,TILETOPX(0),TILETOPX(3),TILETOPX(0),TILETOPX(1),TILETOPX(3),TILETOPX(1),TILETOPX(3),TILETOPX(4),TILETOPX(0),TILETOPX(4),
                            MAPFLAGENEMY,2,TILETOPX(0),TILETOPX(2),TILETOPX(0),TILETOPX(1),TILETOPX(3),TILETOPX(1),TILETOPX(3),TILETOPX(4),TILETOPX(0),TILETOPX(4),
                            
                            MAPFLAGCOIN,TILETOPX(0),TILETOPX(0),
                            
                            MAPFLAGEND};

const byte gamemap4[] PROGMEM = {3,
                            18,8,
                            0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
                            0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
                            0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
                            2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,
                            2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,
                            0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
                            0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
                            0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
                            
                            TILETOPX(1),TILETOPX(3) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,5,TILETOPX(3),TILETOPX(0),TILETOPX(3),TILETOPX(7),
                            MAPFLAGENEMY,5,TILETOPX(5),TILETOPX(0),TILETOPX(5),TILETOPX(7),
                            MAPFLAGENEMY,5,TILETOPX(7),TILETOPX(0),TILETOPX(7),TILETOPX(7),
                            MAPFLAGENEMY,5,TILETOPX(9),TILETOPX(0),TILETOPX(9),TILETOPX(7),
                            MAPFLAGENEMY,5,TILETOPX(11),TILETOPX(0),TILETOPX(11),TILETOPX(7),
                            MAPFLAGENEMY,5,TILETOPX(13),TILETOPX(0),TILETOPX(13),TILETOPX(7),
                            MAPFLAGENEMY,5,TILETOPX(4),TILETOPX(7),TILETOPX(4),TILETOPX(0),
                            MAPFLAGENEMY,5,TILETOPX(6),TILETOPX(7),TILETOPX(6),TILETOPX(0),
                            MAPFLAGENEMY,5,TILETOPX(8),TILETOPX(7),TILETOPX(8),TILETOPX(0),
                            MAPFLAGENEMY,5,TILETOPX(10),TILETOPX(7),TILETOPX(10),TILETOPX(0),
                            MAPFLAGENEMY,5,TILETOPX(12),TILETOPX(7),TILETOPX(12),TILETOPX(0),
                            MAPFLAGENEMY,5,TILETOPX(14),TILETOPX(7),TILETOPX(14),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX(3),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX(14),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX(3),TILETOPX(7),
                            MAPFLAGCOIN,TILETOPX(14),TILETOPX(7),
                            MAPFLAGEND};

const byte gamemap5[] PROGMEM = {3,
                            12,10,
                            1,1,1,1,0,0,1,1,1,1,0,0,
                            1,2,0,1,1,1,1,0,0,1,0,0,
                            1,0,0,1,0,0,1,0,0,1,0,0,
                            1,1,1,1,0,0,1,1,1,1,0,0,
                            1,0,0,1,0,0,1,0,0,1,3,3,
                            1,0,0,1,0,0,1,0,0,1,3,3,
                            1,1,1,1,0,0,1,1,1,1,0,0,
                            1,0,0,1,0,0,1,0,0,1,0,0,
                            1,0,0,1,1,1,1,0,0,1,0,0,
                            1,1,1,1,0,0,1,1,1,1,0,0,
                            
                            TILETOPX(1),TILETOPX(1),
                            
                            MAPFLAGENEMY,2,TILETOPX(3),TILETOPX(0),TILETOPX(3),TILETOPX(3),TILETOPX(0),TILETOPX(3),TILETOPX(0),TILETOPX(0),
                            MAPFLAGENEMY,2,TILETOPX(3),TILETOPX(3),TILETOPX(3),TILETOPX(6),TILETOPX(0),TILETOPX(6),TILETOPX(0),TILETOPX(3),
                            MAPFLAGENEMY,2,TILETOPX(3),TILETOPX(6),TILETOPX(3),TILETOPX(9),TILETOPX(0),TILETOPX(9),TILETOPX(0),TILETOPX(6),
                            
                            MAPFLAGENEMY,2,TILETOPX(6),TILETOPX(0),TILETOPX(6),TILETOPX(3),TILETOPX(9),TILETOPX(3),TILETOPX(9),TILETOPX(0),
                            MAPFLAGENEMY,2,TILETOPX(6),TILETOPX(3),TILETOPX(6),TILETOPX(6),TILETOPX(9),TILETOPX(6),TILETOPX(9),TILETOPX(3),
                            MAPFLAGENEMY,2,TILETOPX(6),TILETOPX(6),TILETOPX(6),TILETOPX(9),TILETOPX(9),TILETOPX(9),TILETOPX(9),TILETOPX(6),
                            
                            MAPFLAGENEMY,2,TILETOPX(3),TILETOPX(1),TILETOPX(6),TILETOPX(1),TILETOPX(6),TILETOPX(8),TILETOPX(3),TILETOPX(8),
                            
                            MAPFLAGCOIN,TILETOPX(0),TILETOPX(9),
                            MAPFLAGCOIN,TILETOPX(9),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX(9),TILETOPX(9),
                            MAPFLAGEND};

const byte gamemap6[] PROGMEM = {4,
                            18,10,
                            2,2,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,
                            2,2,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,
                            1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,
                            1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,
                            1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,4,4,
                            1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,4,4,
                            1,1,0,0,1,1,1,1,3,3,1,1,1,1,0,0,0,0,
                            1,1,0,0,1,1,1,1,3,3,1,1,1,1,0,0,0,0,
                            1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,
                            1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,
                            
                            TILETOPX(0) + (MAPTILESIZE / 2),TILETOPX(0) + (MAPTILESIZE / 2), TILETOPX(8) + (MAPTILESIZE / 2),TILETOPX(6) + (MAPTILESIZE / 2),
                            
                            
                            MAPFLAGENEMY,2,TILETOPX(0),TILETOPX(2),TILETOPX(1),TILETOPX(2),TILETOPX(1),TILETOPX(3),TILETOPX(0),TILETOPX(3),
                            MAPFLAGENEMY,0,TILETOPX(1),TILETOPX(4) + (MAPTILESIZE / 2),
                            MAPFLAGENEMY,0,TILETOPX(0),TILETOPX(6) + (MAPTILESIZE / 2),
                            MAPFLAGENEMY,2,TILETOPX(1),TILETOPX(9),TILETOPX(0),TILETOPX(9),TILETOPX(0),TILETOPX(8),TILETOPX(1),TILETOPX(8),
                            
                            MAPFLAGENEMY,0,TILETOPX(2) + (MAPTILESIZE / 2),TILETOPX(2),
                            MAPFLAGENEMY,0,TILETOPX(2) + (MAPTILESIZE / 2),TILETOPX(8),
                            
                            MAPFLAGENEMY,0,TILETOPX(4),TILETOPX(0) + (MAPTILESIZE / 2),
                            MAPFLAGENEMY,2,TILETOPX(5),TILETOPX(3),TILETOPX(4),TILETOPX(3),TILETOPX(4),TILETOPX(2),TILETOPX(5),TILETOPX(2),
                            MAPFLAGENEMY,0,TILETOPX(4),TILETOPX(6) + (MAPTILESIZE / 2),
                            MAPFLAGENEMY,2,TILETOPX(5),TILETOPX(9),TILETOPX(4),TILETOPX(9),TILETOPX(4),TILETOPX(8),TILETOPX(5),TILETOPX(8),
                            
                            MAPFLAGENEMY,0,TILETOPX(6) + (MAPTILESIZE / 2),TILETOPX(1),
                            MAPFLAGENEMY,0,TILETOPX(5) + (MAPTILESIZE / 2),TILETOPX(6),
                            MAPFLAGENEMY,0,TILETOPX(7),TILETOPX(7),
                            
                            MAPFLAGENEMY,2,TILETOPX(9),TILETOPX(1),TILETOPX(8),TILETOPX(1),TILETOPX(8),TILETOPX(0),TILETOPX(9),TILETOPX(0),
                            MAPFLAGENEMY,0,TILETOPX(8),TILETOPX(2) + (MAPTILESIZE / 2),
                            MAPFLAGENEMY,2,TILETOPX(8),TILETOPX(5),TILETOPX(9),TILETOPX(5),TILETOPX(9),TILETOPX(2) + (MAPTILESIZE / 2),TILETOPX(9),TILETOPX(5),
                            
                            MAPFLAGENEMY,2,TILETOPX(12),TILETOPX(0),TILETOPX(13),TILETOPX(0),TILETOPX(13),TILETOPX(1),TILETOPX(12),TILETOPX(1),
                            MAPFLAGENEMY,0,TILETOPX(13),TILETOPX(2) + (MAPTILESIZE / 2),
                            MAPFLAGENEMY,0,TILETOPX(12),TILETOPX(4) + (MAPTILESIZE / 2),
                            MAPFLAGENEMY,2,TILETOPX(12),TILETOPX(6),TILETOPX(13),TILETOPX(6),TILETOPX(13),TILETOPX(7),TILETOPX(12),TILETOPX(7),
                            MAPFLAGENEMY,0,TILETOPX(12),TILETOPX(8) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,0,TILETOPX(14) + (MAPTILESIZE / 2),TILETOPX(1),
                            MAPFLAGENEMY,2,TILETOPX(13),TILETOPX(8),TILETOPX(15) + (MAPTILESIZE / 2),TILETOPX(8),TILETOPX(15) + (MAPTILESIZE / 2),TILETOPX(9),TILETOPX(15) + (MAPTILESIZE / 2),TILETOPX(8),
                            
                            MAPFLAGENEMY,2,TILETOPX(17),TILETOPX(1),TILETOPX(16),TILETOPX(1),TILETOPX(16),TILETOPX(0),TILETOPX(17),TILETOPX(0),
                            MAPFLAGENEMY,0,TILETOPX(16),TILETOPX(2) + (MAPTILESIZE / 2),
                            
                            MAPFLAGCOIN,TILETOPX(16) + (MAPTILESIZE / 2),TILETOPX(8) + (MAPTILESIZE / 2),
                            
                            MAPFLAGEND};

const byte gamemap7[] PROGMEM = {3,
                            9,10,
                            0,0,2,2,2,0,3,3,3,
                            0,0,2,2,2,0,3,3,3,
                            0,0,1,0,0,0,1,0,0,
                            0,0,1,1,0,1,1,0,0,
                            0,0,1,1,0,1,1,0,0,
                            0,0,1,1,0,1,1,0,0,
                            1,1,1,1,0,1,1,1,1,
                            1,1,0,0,0,0,0,1,1,
                            1,1,1,1,1,1,1,1,1,
                            0,0,1,1,1,1,1,0,0,
                            
                            TILETOPX(3),TILETOPX(0) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,1,TILETOPX(2),TILETOPX(3),TILETOPX(3)+1,TILETOPX(3),
                            MAPFLAGENEMY,1,TILETOPX(3)+1,TILETOPX(4),TILETOPX(2),TILETOPX(4),
                            MAPFLAGENEMY,1,TILETOPX(2),TILETOPX(5),TILETOPX(3)+1,TILETOPX(5),
                            MAPFLAGENEMY,1,TILETOPX(3)+1,TILETOPX(6),TILETOPX(2),TILETOPX(6),
                            
                            MAPFLAGENEMY,1,TILETOPX(1),TILETOPX(6),TILETOPX(0)-1,TILETOPX(6),
                            MAPFLAGENEMY,1,TILETOPX(0)-1,TILETOPX(7),TILETOPX(1),TILETOPX(7),
                            MAPFLAGENEMY,1,TILETOPX(1),TILETOPX(8),TILETOPX(0)-1,TILETOPX(8),
                            
                            MAPFLAGENEMY,1,TILETOPX(2),TILETOPX(8),TILETOPX(2),TILETOPX(9)+1,
                            MAPFLAGENEMY,1,TILETOPX(3),TILETOPX(9)+1,TILETOPX(3),TILETOPX(8),
                            MAPFLAGENEMY,1,TILETOPX(4),TILETOPX(8),TILETOPX(4),TILETOPX(9)+1,
                            MAPFLAGENEMY,1,TILETOPX(5),TILETOPX(9)+1,TILETOPX(5),TILETOPX(8),
                            MAPFLAGENEMY,1,TILETOPX(6),TILETOPX(8),TILETOPX(6),TILETOPX(9)+1,
                            
                            MAPFLAGENEMY,1,TILETOPX(7),TILETOPX(8),TILETOPX(8)+1,TILETOPX(8),
                            MAPFLAGENEMY,1,TILETOPX(8)+1,TILETOPX(7),TILETOPX(7),TILETOPX(7),
                            MAPFLAGENEMY,1,TILETOPX(7),TILETOPX(6),TILETOPX(8)+1,TILETOPX(6),
                            
                            
                            MAPFLAGENEMY,1,TILETOPX(5)-1,TILETOPX(6),TILETOPX(6),TILETOPX(6),
                            MAPFLAGENEMY,1,TILETOPX(6),TILETOPX(5),TILETOPX(5)-1,TILETOPX(5),
                            MAPFLAGENEMY,1,TILETOPX(5)-1,TILETOPX(4),TILETOPX(6),TILETOPX(4),
                            MAPFLAGENEMY,1,TILETOPX(6),TILETOPX(3),TILETOPX(5)-1,TILETOPX(3),
                            
                            MAPFLAGEND};

const byte gamemap8[] PROGMEM = {3,
                            10,10,
                            0,0,0,0,3,3,0,0,0,0,
                            0,0,0,0,3,3,0,0,0,0,
                            1,1,1,1,1,1,1,1,1,1,
                            1,1,1,1,1,1,1,1,1,1,
                            1,1,1,1,1,1,1,1,1,1,
                            1,1,1,1,1,1,1,1,1,1,
                            1,1,1,1,1,1,1,1,1,1,
                            1,1,1,1,1,1,1,1,1,1,
                            0,0,0,0,2,2,0,0,0,0,
                            0,0,0,0,2,2,0,0,0,0,
                            
                            TILETOPX(4) + (MAPTILESIZE / 2),TILETOPX(8) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,3,TILETOPX(0),TILETOPX(2),TILETOPX(0),TILETOPX(7),
                            MAPFLAGENEMY,3,TILETOPX(1),TILETOPX(7),TILETOPX(1),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX(2),TILETOPX(2),TILETOPX(2),TILETOPX(7),
                            MAPFLAGENEMY,3,TILETOPX(3),TILETOPX(7),TILETOPX(3),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX(4),TILETOPX(2),TILETOPX(4),TILETOPX(7),
                            MAPFLAGENEMY,3,TILETOPX(5),TILETOPX(7),TILETOPX(5),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX(6),TILETOPX(2),TILETOPX(6),TILETOPX(7),
                            MAPFLAGENEMY,3,TILETOPX(7),TILETOPX(7),TILETOPX(7),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX(8),TILETOPX(2),TILETOPX(8),TILETOPX(7),
                            MAPFLAGENEMY,3,TILETOPX(9),TILETOPX(7),TILETOPX(9),TILETOPX(2),
                            
                            MAPFLAGENEMY,3,TILETOPX(0),TILETOPX(4),TILETOPX(9),TILETOPX(4),
                            MAPFLAGENEMY,3,TILETOPX(9),TILETOPX(5),TILETOPX(0),TILETOPX(5),
                            
                            MAPFLAGEND};

const byte gamemap9[] PROGMEM = {3,
                            20,10,
                            2,2,2,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,
                            2,2,2,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,
                            1,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,
                            1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,1,
                            1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,1,
                            1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,1,
                            1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,1,
                            1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,1,
                            1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,3,3,3,
                            1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,3,3,3,
                            
                            TILETOPX(1),TILETOPX(0) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,3,TILETOPX(0),TILETOPX(9),TILETOPX(0),TILETOPX(3),
                            MAPFLAGENEMY,3,TILETOPX(1),TILETOPX(3),TILETOPX(1),TILETOPX(9),
                            MAPFLAGENEMY,3,TILETOPX(2),TILETOPX(9),TILETOPX(2),TILETOPX(3),
                            
                            MAPFLAGENEMY,4,TILETOPX(3),TILETOPX(9),TILETOPX(3),TILETOPX(7),
                            
                            MAPFLAGENEMY,3,TILETOPX(4),TILETOPX(9),TILETOPX(4),TILETOPX(0),
                            MAPFLAGENEMY,3,TILETOPX(5),TILETOPX(0),TILETOPX(5),TILETOPX(9),
                            MAPFLAGENEMY,3,TILETOPX(6),TILETOPX(9),TILETOPX(6),TILETOPX(0),
                            
                            MAPFLAGENEMY,4,TILETOPX(7),TILETOPX(0),TILETOPX(7),TILETOPX(2),
                            
                            MAPFLAGENEMY,3,TILETOPX(8),TILETOPX(9),TILETOPX(8),TILETOPX(0),
                            MAPFLAGENEMY,3,TILETOPX(9),TILETOPX(0),TILETOPX(9),TILETOPX(9),
                            MAPFLAGENEMY,3,TILETOPX(10),TILETOPX(9),TILETOPX(10),TILETOPX(0),
                            
                            MAPFLAGENEMY,4,TILETOPX(11),TILETOPX(9),TILETOPX(11),TILETOPX(7),
                            
                            MAPFLAGENEMY,3,TILETOPX(12),TILETOPX(9),TILETOPX(12),TILETOPX(0),
                            MAPFLAGENEMY,3,TILETOPX(13),TILETOPX(0),TILETOPX(13),TILETOPX(9),
                            MAPFLAGENEMY,3,TILETOPX(14),TILETOPX(9),TILETOPX(14),TILETOPX(0),
                            
                            MAPFLAGENEMY,4,TILETOPX(15),TILETOPX(0),TILETOPX(15),TILETOPX(2),
                            MAPFLAGENEMY,4,TILETOPX(16),TILETOPX(2),TILETOPX(16),TILETOPX(0),
                            
                            MAPFLAGENEMY,3,TILETOPX(17),TILETOPX(0),TILETOPX(17),TILETOPX(6),
                            MAPFLAGENEMY,3,TILETOPX(18),TILETOPX(6),TILETOPX(18),TILETOPX(0),
                            MAPFLAGENEMY,3,TILETOPX(19),TILETOPX(0),TILETOPX(19),TILETOPX(6),
                            
                            MAPFLAGEND};

const byte gamemap10[] PROGMEM = {3,
                            20,6,
                            0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,
                            0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,
                            2,2,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,3,3,
                            2,2,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,3,3,
                            0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,
                            0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,
                            
                            TILETOPX(0) + (MAPTILESIZE / 2),TILETOPX(2) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,1,TILETOPX(2),TILETOPX(0),TILETOPX(3),TILETOPX(0),TILETOPX(3),TILETOPX(1),TILETOPX(2),TILETOPX(1),
                            MAPFLAGENEMY,1,TILETOPX(4),TILETOPX(0),TILETOPX(5),TILETOPX(0),TILETOPX(5),TILETOPX(1),TILETOPX(4),TILETOPX(1),
                            MAPFLAGENEMY,1,TILETOPX(2),TILETOPX(2),TILETOPX(3),TILETOPX(2),TILETOPX(3),TILETOPX(3),TILETOPX(2),TILETOPX(3),
                            MAPFLAGENEMY,1,TILETOPX(4),TILETOPX(2),TILETOPX(5),TILETOPX(2),TILETOPX(5),TILETOPX(3),TILETOPX(4),TILETOPX(3),
                            MAPFLAGENEMY,1,TILETOPX(2),TILETOPX(4),TILETOPX(3),TILETOPX(4),TILETOPX(3),TILETOPX(5),TILETOPX(2),TILETOPX(5),
                            MAPFLAGENEMY,1,TILETOPX(4),TILETOPX(4),TILETOPX(5),TILETOPX(4),TILETOPX(5),TILETOPX(5),TILETOPX(4),TILETOPX(5),
                            
                            MAPFLAGENEMY,1,TILETOPX(6),TILETOPX(4),TILETOPX(7),TILETOPX(4),TILETOPX(7),TILETOPX(5),TILETOPX(6),TILETOPX(5),
                            
                            MAPFLAGENEMY,1,TILETOPX(8),TILETOPX(0),TILETOPX(9),TILETOPX(0),TILETOPX(9),TILETOPX(1),TILETOPX(8),TILETOPX(1),
                            MAPFLAGENEMY,1,TILETOPX(10),TILETOPX(0),TILETOPX(11),TILETOPX(0),TILETOPX(11),TILETOPX(1),TILETOPX(10),TILETOPX(1),
                            MAPFLAGENEMY,1,TILETOPX(8),TILETOPX(2),TILETOPX(9),TILETOPX(2),TILETOPX(9),TILETOPX(3),TILETOPX(8),TILETOPX(3),
                            MAPFLAGENEMY,1,TILETOPX(10),TILETOPX(2),TILETOPX(11),TILETOPX(2),TILETOPX(11),TILETOPX(3),TILETOPX(10),TILETOPX(3),
                            MAPFLAGENEMY,1,TILETOPX(8),TILETOPX(4),TILETOPX(9),TILETOPX(4),TILETOPX(9),TILETOPX(5),TILETOPX(8),TILETOPX(5),
                            MAPFLAGENEMY,1,TILETOPX(10),TILETOPX(4),TILETOPX(11),TILETOPX(4),TILETOPX(11),TILETOPX(5),TILETOPX(10),TILETOPX(5),
                            
                            MAPFLAGENEMY,1,TILETOPX(12),TILETOPX(0),TILETOPX(13),TILETOPX(0),TILETOPX(13),TILETOPX(1),TILETOPX(12),TILETOPX(1),
                            
                            MAPFLAGENEMY,1,TILETOPX(14),TILETOPX(0),TILETOPX(15),TILETOPX(0),TILETOPX(15),TILETOPX(1),TILETOPX(14),TILETOPX(1),
                            MAPFLAGENEMY,1,TILETOPX(16),TILETOPX(0),TILETOPX(17),TILETOPX(0),TILETOPX(17),TILETOPX(1),TILETOPX(16),TILETOPX(1),
                            MAPFLAGENEMY,1,TILETOPX(14),TILETOPX(2),TILETOPX(15),TILETOPX(2),TILETOPX(15),TILETOPX(3),TILETOPX(14),TILETOPX(3),
                            MAPFLAGENEMY,1,TILETOPX(16),TILETOPX(2),TILETOPX(17),TILETOPX(2),TILETOPX(17),TILETOPX(3),TILETOPX(16),TILETOPX(3),
                            MAPFLAGENEMY,1,TILETOPX(14),TILETOPX(4),TILETOPX(15),TILETOPX(4),TILETOPX(15),TILETOPX(5),TILETOPX(14),TILETOPX(5),
                            MAPFLAGENEMY,1,TILETOPX(16),TILETOPX(4),TILETOPX(17),TILETOPX(4),TILETOPX(17),TILETOPX(5),TILETOPX(16),TILETOPX(5),
                            
                            MAPFLAGCOIN,TILETOPX(5),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX(8),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX(11),TILETOPX(5),
                            MAPFLAGCOIN,TILETOPX(14),TILETOPX(5),
                            
                            MAPFLAGEND};

const byte gamemap11[] PROGMEM = {3,
                            16,12,
                            0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
                            0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                            0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,
                            0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,
                            0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,
                            0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,
                            0,0,1,0,1,1,1,1,1,1,1,3,1,1,0,0,
                            0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
                            0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,
                            0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,
                            
                            TILETOPX(1),TILETOPX(1),
                            
                            MAPFLAGENEMY,0,TILETOPX(3),TILETOPX(2),
                            MAPFLAGENEMY,0,TILETOPX(6),TILETOPX(3),
                            MAPFLAGENEMY,0,TILETOPX(6),TILETOPX(8),
                            MAPFLAGENEMY,0,TILETOPX(6),TILETOPX(10),
                            MAPFLAGENEMY,0,TILETOPX(12),TILETOPX(7),
                            
                            MAPFLAGENEMY,2,TILETOPX(4),TILETOPX(4),TILETOPX(13),TILETOPX(4),
                            MAPFLAGENEMY,2,TILETOPX(4),TILETOPX(7),TILETOPX(13),TILETOPX(7),
                            
                            MAPFLAGENEMY,2,TILETOPX(2),TILETOPX(0),TILETOPX(2),TILETOPX(9),
                            MAPFLAGENEMY,2,TILETOPX(13),TILETOPX(11),TILETOPX(13),TILETOPX(2),
                            
                            MAPFLAGENEMY,2,TILETOPX(0),TILETOPX(9),TILETOPX(13),TILETOPX(9),
                            MAPFLAGENEMY,2,TILETOPX(15),TILETOPX(2),TILETOPX(2),TILETOPX(2),
                            
                            MAPFLAGENEMY,2,TILETOPX(6),TILETOPX(9) + (MAPTILESIZE / 2),TILETOPX(6),TILETOPX(11),TILETOPX(6),TILETOPX(2),
                            
                            MAPFLAGEND};

const byte gamemap12[] PROGMEM = {3,
                            14,4,
                            0,0,1,1,1,1,1,1,1,1,1,1,0,0,
                            2,2,1,1,1,1,1,1,1,1,1,1,3,3,
                            2,2,1,1,1,1,1,1,1,1,1,1,3,3,
                            0,0,1,1,1,1,1,1,1,1,1,1,0,0,
                            
                            TILETOPX(0) + (MAPTILESIZE / 2),TILETOPX(1) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,2,TILETOPX(2),TILETOPX(0),TILETOPX(2),TILETOPX(3),
                            MAPFLAGENEMY,2,TILETOPX(3),TILETOPX(3),TILETOPX(3),TILETOPX(0),
                            MAPFLAGENEMY,2,TILETOPX(4),TILETOPX(0),TILETOPX(4),TILETOPX(3),
                            MAPFLAGENEMY,2,TILETOPX(5),TILETOPX(3),TILETOPX(5),TILETOPX(0),
                            MAPFLAGENEMY,2,TILETOPX(6),TILETOPX(0),TILETOPX(6),TILETOPX(3),
                            MAPFLAGENEMY,2,TILETOPX(7),TILETOPX(3),TILETOPX(7),TILETOPX(0),
                            MAPFLAGENEMY,2,TILETOPX(8),TILETOPX(0),TILETOPX(8),TILETOPX(3),
                            MAPFLAGENEMY,2,TILETOPX(9),TILETOPX(3),TILETOPX(9),TILETOPX(0),
                            MAPFLAGENEMY,2,TILETOPX(10),TILETOPX(0),TILETOPX(10),TILETOPX(3),
                            MAPFLAGENEMY,2,TILETOPX(11),TILETOPX(3),TILETOPX(11),TILETOPX(0),
                            
                            MAPFLAGCOIN,TILETOPX( 2),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX( 3),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX( 4),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX( 5),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX( 6),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX( 7),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX( 8),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX( 9),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX(10),TILETOPX(0),
                            MAPFLAGCOIN,TILETOPX(11),TILETOPX(0),
                            
                            MAPFLAGCOIN,TILETOPX( 2),TILETOPX(1),
                            MAPFLAGCOIN,TILETOPX( 3),TILETOPX(1),
                            MAPFLAGCOIN,TILETOPX( 4),TILETOPX(1),
                            MAPFLAGCOIN,TILETOPX( 5),TILETOPX(1),
                            MAPFLAGCOIN,TILETOPX( 6),TILETOPX(1),
                            MAPFLAGCOIN,TILETOPX( 7),TILETOPX(1),
                            MAPFLAGCOIN,TILETOPX( 8),TILETOPX(1),
                            MAPFLAGCOIN,TILETOPX( 9),TILETOPX(1),
                            MAPFLAGCOIN,TILETOPX(10),TILETOPX(1),
                            MAPFLAGCOIN,TILETOPX(11),TILETOPX(1),
                            
                            MAPFLAGCOIN,TILETOPX( 2),TILETOPX(2),
                            MAPFLAGCOIN,TILETOPX( 3),TILETOPX(2),
                            MAPFLAGCOIN,TILETOPX( 4),TILETOPX(2),
                            MAPFLAGCOIN,TILETOPX( 5),TILETOPX(2),
                            MAPFLAGCOIN,TILETOPX( 6),TILETOPX(2),
                            MAPFLAGCOIN,TILETOPX( 7),TILETOPX(2),
                            MAPFLAGCOIN,TILETOPX( 8),TILETOPX(2),
                            MAPFLAGCOIN,TILETOPX( 9),TILETOPX(2),
                            MAPFLAGCOIN,TILETOPX(10),TILETOPX(2),
                            MAPFLAGCOIN,TILETOPX(11),TILETOPX(2),
                            
                            MAPFLAGCOIN,TILETOPX( 2),TILETOPX(3),
                            MAPFLAGCOIN,TILETOPX( 3),TILETOPX(3),
                            MAPFLAGCOIN,TILETOPX( 4),TILETOPX(3),
                            MAPFLAGCOIN,TILETOPX( 5),TILETOPX(3),
                            MAPFLAGCOIN,TILETOPX( 6),TILETOPX(3),
                            MAPFLAGCOIN,TILETOPX( 7),TILETOPX(3),
                            MAPFLAGCOIN,TILETOPX( 8),TILETOPX(3),
                            MAPFLAGCOIN,TILETOPX( 9),TILETOPX(3),
                            MAPFLAGCOIN,TILETOPX(10),TILETOPX(3),
                            MAPFLAGCOIN,TILETOPX(11),TILETOPX(3),
                            
                            MAPFLAGCOIN,TILETOPX( 2) + (MAPTILESIZE / 2),TILETOPX(0) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 3) + (MAPTILESIZE / 2),TILETOPX(0) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 4) + (MAPTILESIZE / 2),TILETOPX(0) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 5) + (MAPTILESIZE / 2),TILETOPX(0) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 6) + (MAPTILESIZE / 2),TILETOPX(0) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 7) + (MAPTILESIZE / 2),TILETOPX(0) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 8) + (MAPTILESIZE / 2),TILETOPX(0) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 9) + (MAPTILESIZE / 2),TILETOPX(0) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX(10) + (MAPTILESIZE / 2),TILETOPX(0) + (MAPTILESIZE / 2),
                            
                            MAPFLAGCOIN,TILETOPX( 2) + (MAPTILESIZE / 2),TILETOPX(1) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 3) + (MAPTILESIZE / 2),TILETOPX(1) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 4) + (MAPTILESIZE / 2),TILETOPX(1) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 5) + (MAPTILESIZE / 2),TILETOPX(1) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 6) + (MAPTILESIZE / 2),TILETOPX(1) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 7) + (MAPTILESIZE / 2),TILETOPX(1) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 8) + (MAPTILESIZE / 2),TILETOPX(1) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 9) + (MAPTILESIZE / 2),TILETOPX(1) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX(10) + (MAPTILESIZE / 2),TILETOPX(1) + (MAPTILESIZE / 2),
                            
                            MAPFLAGCOIN,TILETOPX( 2) + (MAPTILESIZE / 2),TILETOPX(2) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 3) + (MAPTILESIZE / 2),TILETOPX(2) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 4) + (MAPTILESIZE / 2),TILETOPX(2) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 5) + (MAPTILESIZE / 2),TILETOPX(2) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 6) + (MAPTILESIZE / 2),TILETOPX(2) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 7) + (MAPTILESIZE / 2),TILETOPX(2) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 8) + (MAPTILESIZE / 2),TILETOPX(2) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX( 9) + (MAPTILESIZE / 2),TILETOPX(2) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX(10) + (MAPTILESIZE / 2),TILETOPX(2) + (MAPTILESIZE / 2),
                            
                            MAPFLAGEND};

const byte gamemap13[] PROGMEM = {3,
                            16,6,
                            0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
                            2,2,1,1,1,1,1,1,1,1,1,1,1,1,3,3,
                            2,2,1,1,1,1,1,1,1,1,1,1,1,1,3,3,
                            2,2,1,1,1,1,1,1,1,1,1,1,1,1,3,3,
                            2,2,1,1,1,1,1,1,1,1,1,1,1,1,3,3,
                            0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
                            TILETOPX(0) + (MAPTILESIZE / 2),TILETOPX(2) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,2,TILETOPX(2),TILETOPX(0), TILETOPX(7),TILETOPX(5), TILETOPX(12),TILETOPX(0), TILETOPX(13),TILETOPX(1), TILETOPX(9),TILETOPX(5), TILETOPX(4),TILETOPX(0), TILETOPX(2),TILETOPX(2), TILETOPX(5),TILETOPX(5), 
                                           TILETOPX(10),TILETOPX(0), TILETOPX(13),TILETOPX(3), TILETOPX(11),TILETOPX(5), TILETOPX(6),TILETOPX(0), TILETOPX(2),TILETOPX(4), TILETOPX(3),TILETOPX(5), TILETOPX(8),TILETOPX(0), TILETOPX(13),TILETOPX(5),
                                           
                                           TILETOPX(8),TILETOPX(0), TILETOPX(3),TILETOPX(5), TILETOPX(2),TILETOPX(4), TILETOPX(6),TILETOPX(0), TILETOPX(11),TILETOPX(5), TILETOPX(13),TILETOPX(3), TILETOPX(10),TILETOPX(0), TILETOPX(5),TILETOPX(5),
                                           TILETOPX(2),TILETOPX(2), TILETOPX(4),TILETOPX(0), TILETOPX(9),TILETOPX(5), TILETOPX(13),TILETOPX(1), TILETOPX(12),TILETOPX(0), TILETOPX(7),TILETOPX(5),
                            
                            MAPFLAGENEMY,2,TILETOPX(13),TILETOPX(5), TILETOPX(8),TILETOPX(0), TILETOPX(3),TILETOPX(5), TILETOPX(2),TILETOPX(4), TILETOPX(6),TILETOPX(0), TILETOPX(11),TILETOPX(5), TILETOPX(13),TILETOPX(3), TILETOPX(10),TILETOPX(0),
                                           TILETOPX(5),TILETOPX(5), TILETOPX(2),TILETOPX(2), TILETOPX(4),TILETOPX(0), TILETOPX(9),TILETOPX(5), TILETOPX(13),TILETOPX(1), TILETOPX(12),TILETOPX(0), TILETOPX(7),TILETOPX(5),
                                           
                                           TILETOPX(2),TILETOPX(0), TILETOPX(7),TILETOPX(5), TILETOPX(12),TILETOPX(0), TILETOPX(13),TILETOPX(1), TILETOPX(9),TILETOPX(5), TILETOPX(4),TILETOPX(0), TILETOPX(2),TILETOPX(2), TILETOPX(5),TILETOPX(5), 
                                           TILETOPX(10),TILETOPX(0), TILETOPX(13),TILETOPX(3), TILETOPX(11),TILETOPX(5), TILETOPX(6),TILETOPX(0), TILETOPX(2),TILETOPX(4), TILETOPX(3),TILETOPX(5), TILETOPX(8),TILETOPX(0),
                            
                            MAPFLAGENEMY,2,TILETOPX(2),TILETOPX(5), TILETOPX(7),TILETOPX(0), TILETOPX(12),TILETOPX(5), TILETOPX(13),TILETOPX(4), TILETOPX(9),TILETOPX(0), TILETOPX(4),TILETOPX(5), TILETOPX(2),TILETOPX(3), TILETOPX(5),TILETOPX(0), 
                                           TILETOPX(10),TILETOPX(5), TILETOPX(13),TILETOPX(2), TILETOPX(11),TILETOPX(0), TILETOPX(6),TILETOPX(5), TILETOPX(2),TILETOPX(1), TILETOPX(3),TILETOPX(0), TILETOPX(8),TILETOPX(5), TILETOPX(13),TILETOPX(0),
                                           
                                           TILETOPX(8),TILETOPX(5), TILETOPX(3),TILETOPX(0), TILETOPX(2),TILETOPX(1), TILETOPX(6),TILETOPX(5), TILETOPX(11),TILETOPX(0), TILETOPX(13),TILETOPX(2), TILETOPX(10),TILETOPX(5), TILETOPX(5),TILETOPX(0),
                                           TILETOPX(2),TILETOPX(3), TILETOPX(4),TILETOPX(5), TILETOPX(9),TILETOPX(0), TILETOPX(13),TILETOPX(4), TILETOPX(12),TILETOPX(5), TILETOPX(7),TILETOPX(0),
                            
                            MAPFLAGENEMY,2,TILETOPX(13),TILETOPX(0), TILETOPX(8),TILETOPX(5), TILETOPX(3),TILETOPX(0), TILETOPX(2),TILETOPX(1), TILETOPX(6),TILETOPX(5), TILETOPX(11),TILETOPX(0), TILETOPX(13),TILETOPX(2), TILETOPX(10),TILETOPX(5),
                                           TILETOPX(5),TILETOPX(0), TILETOPX(2),TILETOPX(3), TILETOPX(4),TILETOPX(5), TILETOPX(9),TILETOPX(0), TILETOPX(13),TILETOPX(4), TILETOPX(12),TILETOPX(5), TILETOPX(7),TILETOPX(0),
                                           
                                           TILETOPX(2),TILETOPX(5), TILETOPX(7),TILETOPX(0), TILETOPX(12),TILETOPX(5), TILETOPX(13),TILETOPX(4), TILETOPX(9),TILETOPX(0), TILETOPX(4),TILETOPX(5), TILETOPX(2),TILETOPX(3), TILETOPX(5),TILETOPX(0), 
                                           TILETOPX(10),TILETOPX(5), TILETOPX(13),TILETOPX(2), TILETOPX(11),TILETOPX(0), TILETOPX(6),TILETOPX(5), TILETOPX(2),TILETOPX(1), TILETOPX(3),TILETOPX(0), TILETOPX(8),TILETOPX(5),
                            
                            MAPFLAGENEMY,3,TILETOPX(2),TILETOPX(0),TILETOPX(2),TILETOPX(5),
                            MAPFLAGENEMY,3,TILETOPX(3),TILETOPX(5),TILETOPX(3),TILETOPX(0),
                            MAPFLAGENEMY,3,TILETOPX(4),TILETOPX(0),TILETOPX(4),TILETOPX(5),
                            MAPFLAGENEMY,3,TILETOPX(5),TILETOPX(5),TILETOPX(5),TILETOPX(0),
                            MAPFLAGENEMY,3,TILETOPX(6),TILETOPX(0),TILETOPX(6),TILETOPX(5),
                            MAPFLAGENEMY,3,TILETOPX(7),TILETOPX(5),TILETOPX(7),TILETOPX(0),
                            MAPFLAGENEMY,3,TILETOPX(8),TILETOPX(0),TILETOPX(8),TILETOPX(5),
                            MAPFLAGENEMY,3,TILETOPX(9),TILETOPX(5),TILETOPX(9),TILETOPX(0),
                            MAPFLAGENEMY,3,TILETOPX(10),TILETOPX(0),TILETOPX(10),TILETOPX(5),
                            MAPFLAGENEMY,3,TILETOPX(11),TILETOPX(5),TILETOPX(11),TILETOPX(0),
                            MAPFLAGENEMY,3,TILETOPX(12),TILETOPX(0),TILETOPX(12),TILETOPX(5),
                            MAPFLAGENEMY,3,TILETOPX(13),TILETOPX(5),TILETOPX(13),TILETOPX(0),
                            
                            MAPFLAGEND};

const byte gamemap14[] PROGMEM = {3,
                            20,8,
                            3,3,3,1,1,0,1,1,1,1,0,0,1,1,1,1,0,0,1,0,
                            3,3,3,0,1,0,1,0,1,1,0,0,1,0,1,1,0,0,1,0,
                            0,0,0,0,1,0,1,0,0,1,1,1,1,0,0,1,1,1,1,0,
                            0,0,0,0,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,
                            0,0,0,0,1,0,1,0,1,1,0,0,1,0,1,1,0,0,1,0,
                            0,0,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,
                            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,
                            
                            TILETOPX(18) + (MAPTILESIZE / 2),TILETOPX(6) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,2,TILETOPX(6),TILETOPX(0),TILETOPX(6),TILETOPX(5),
                            MAPFLAGENEMY,2,TILETOPX(9),TILETOPX(0),TILETOPX(9),TILETOPX(5),
                            MAPFLAGENEMY,2,TILETOPX(12),TILETOPX(0),TILETOPX(12),TILETOPX(5),
                            MAPFLAGENEMY,2,TILETOPX(15),TILETOPX(0),TILETOPX(15),TILETOPX(5),
                            MAPFLAGENEMY,2,TILETOPX(18),TILETOPX(0),TILETOPX(18),TILETOPX(5),
                            
                            MAPFLAGENEMY,2,TILETOPX(9),TILETOPX(0),TILETOPX(6),TILETOPX(0),
                            MAPFLAGENEMY,2,TILETOPX(9),TILETOPX(3),TILETOPX(6),TILETOPX(3),
                            MAPFLAGENEMY,2,TILETOPX(12),TILETOPX(2),TILETOPX(9),TILETOPX(2),
                            MAPFLAGENEMY,2,TILETOPX(12),TILETOPX(5),TILETOPX(9),TILETOPX(5),
                            MAPFLAGENEMY,2,TILETOPX(15),TILETOPX(0),TILETOPX(12),TILETOPX(0),
                            MAPFLAGENEMY,2,TILETOPX(15),TILETOPX(3),TILETOPX(12),TILETOPX(3),
                            MAPFLAGENEMY,2,TILETOPX(18),TILETOPX(2),TILETOPX(15),TILETOPX(2),
                            MAPFLAGENEMY,2,TILETOPX(18),TILETOPX(5),TILETOPX(15),TILETOPX(5),
                            
                            MAPFLAGCOIN,TILETOPX(8),TILETOPX(1),
                            MAPFLAGCOIN,TILETOPX(8),TILETOPX(4),
                            MAPFLAGCOIN,TILETOPX(11),TILETOPX(3),
                            MAPFLAGCOIN,TILETOPX(14),TILETOPX(1),
                            MAPFLAGCOIN,TILETOPX(14),TILETOPX(4),
                            MAPFLAGCOIN,TILETOPX(17),TILETOPX(3),
                            MAPFLAGCOIN,TILETOPX(18),TILETOPX(1),
                            
                            MAPFLAGEND};

const byte gamemap15[] PROGMEM = {3,
                            18,8,
                            2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
                            2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
                            0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
                            0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
                            0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
                            0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
                            0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,
                            0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,
                            
                            TILETOPX(0) + (MAPTILESIZE / 2),TILETOPX(0) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,4,TILETOPX( 2),TILETOPX(0),TILETOPX( 2),TILETOPX(7),
                            MAPFLAGENEMY,2,TILETOPX( 3),TILETOPX(0),TILETOPX( 3),TILETOPX(7),
                            MAPFLAGENEMY,1,TILETOPX( 4),TILETOPX(0),TILETOPX( 4),TILETOPX(7),
                            MAPFLAGENEMY,4,TILETOPX( 5),TILETOPX(0),TILETOPX( 5),TILETOPX(7),
                            MAPFLAGENEMY,2,TILETOPX( 6),TILETOPX(0),TILETOPX( 6),TILETOPX(7),
                            MAPFLAGENEMY,1,TILETOPX( 7),TILETOPX(0),TILETOPX( 7),TILETOPX(7),
                            MAPFLAGENEMY,4,TILETOPX( 8),TILETOPX(0),TILETOPX( 8),TILETOPX(7),
                            MAPFLAGENEMY,2,TILETOPX( 9),TILETOPX(0),TILETOPX( 9),TILETOPX(7),
                            MAPFLAGENEMY,1,TILETOPX(10),TILETOPX(0),TILETOPX(10),TILETOPX(7),
                            MAPFLAGENEMY,4,TILETOPX(11),TILETOPX(0),TILETOPX(11),TILETOPX(7),
                            MAPFLAGENEMY,2,TILETOPX(12),TILETOPX(0),TILETOPX(12),TILETOPX(7),
                            MAPFLAGENEMY,1,TILETOPX(13),TILETOPX(0),TILETOPX(13),TILETOPX(7),
                            MAPFLAGENEMY,4,TILETOPX(14),TILETOPX(0),TILETOPX(14),TILETOPX(7),
                            MAPFLAGENEMY,2,TILETOPX(15),TILETOPX(0),TILETOPX(15),TILETOPX(7),
                            
                            MAPFLAGCOIN,TILETOPX(2),TILETOPX(7),
                            MAPFLAGCOIN,TILETOPX(8) + (MAPTILESIZE / 2),TILETOPX(3) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX(15),TILETOPX(0),
                            
                            MAPFLAGEND};

const byte gamemap16[] PROGMEM = {3,
                            18,10,
                            1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,2,2,
                            1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,2,2,
                            1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,
                            1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,
                            1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,
                            1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,
                            1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,
                            1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,
                            1,1,3,3,0,0,1,1,1,1,1,1,1,1,1,1,0,0,
                            1,1,3,3,0,0,1,1,1,1,1,1,1,1,1,1,0,0,
                            
                            TILETOPX(16) + (MAPTILESIZE / 2),TILETOPX(0) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,2,TILETOPX(15)+1,TILETOPX(1)+1,TILETOPX(10)-1,TILETOPX(1)+1,TILETOPX(10)-1,TILETOPX(0)-1,TILETOPX(15)+1,TILETOPX(0)-1,
                            MAPFLAGENEMY,2,TILETOPX(10)-1,TILETOPX(0)-1,TILETOPX(15)+1,TILETOPX(0)-1,TILETOPX(15)+1,TILETOPX(1)+1,TILETOPX(10)-1,TILETOPX(1)+1,
                            
                            MAPFLAGENEMY,2,TILETOPX(11)+1,TILETOPX(3)+1,TILETOPX(10)-1,TILETOPX(3)+1,TILETOPX(10)-1,TILETOPX(2)-1,TILETOPX(11)+1,TILETOPX(2)-1,
                            MAPFLAGENEMY,2,TILETOPX(10)-1,TILETOPX(2)-1,TILETOPX(11)+1,TILETOPX(2)-1,TILETOPX(11)+1,TILETOPX(3)+1,TILETOPX(10)-1,TILETOPX(3)+1,
                            
                            MAPFLAGENEMY,2,TILETOPX(15)+1,TILETOPX(5)+1,TILETOPX(10)-1,TILETOPX(5)+1,TILETOPX(10)-1,TILETOPX(4)-1,TILETOPX(15)+1,TILETOPX(4)-1,
                            MAPFLAGENEMY,2,TILETOPX(10)-1,TILETOPX(4)-1,TILETOPX(15)+1,TILETOPX(4)-1,TILETOPX(15)+1,TILETOPX(5)+1,TILETOPX(10)-1,TILETOPX(5)+1,
                            
                            MAPFLAGENEMY,2,TILETOPX(15)+1,TILETOPX(7)+1,TILETOPX(14)-1,TILETOPX(7)+1,TILETOPX(14)-1,TILETOPX(6)-1,TILETOPX(15)+1,TILETOPX(6)-1,
                            MAPFLAGENEMY,2,TILETOPX(14)-1,TILETOPX(6)-1,TILETOPX(15)+1,TILETOPX(6)-1,TILETOPX(15)+1,TILETOPX(7)+1,TILETOPX(14)-1,TILETOPX(7)+1,
                            
                            MAPFLAGENEMY,2,TILETOPX(15)+1,TILETOPX(9)+1,TILETOPX(10)-1,TILETOPX(9)+1,TILETOPX(10)-1,TILETOPX(8)-1,TILETOPX(15)+1,TILETOPX(8)-1,
                            MAPFLAGENEMY,2,TILETOPX(10)-1,TILETOPX(8)-1,TILETOPX(15)+1,TILETOPX(8)-1,TILETOPX(15)+1,TILETOPX(9)+1,TILETOPX(10)-1,TILETOPX(9)+1,
                            
                            MAPFLAGENEMY,2,TILETOPX(9)+1,TILETOPX(9)+1,TILETOPX(8)-1,TILETOPX(9)+1,TILETOPX(8)-1,TILETOPX(8)-1,TILETOPX(9)+1,TILETOPX(8)-1,
                            MAPFLAGENEMY,2,TILETOPX(8)-1,TILETOPX(8)-1,TILETOPX(9)+1,TILETOPX(8)-1,TILETOPX(9)+1,TILETOPX(9)+1,TILETOPX(8)-1,TILETOPX(9)+1,
                            
                            MAPFLAGENEMY,2,TILETOPX(7)+1,TILETOPX(9)+1,TILETOPX(6)-1,TILETOPX(9)+1,TILETOPX(6)-1,TILETOPX(4)-1,TILETOPX(7)+1,TILETOPX(4)-1,
                            MAPFLAGENEMY,2,TILETOPX(6)-1,TILETOPX(4)-1,TILETOPX(7)+1,TILETOPX(4)-1,TILETOPX(7)+1,TILETOPX(9)+1,TILETOPX(6)-1,TILETOPX(9)+1,
                            
                            MAPFLAGENEMY,2,TILETOPX(7)+1,TILETOPX(3)+1,TILETOPX(6)-1,TILETOPX(3)+1,TILETOPX(6)-1,TILETOPX(2)-1,TILETOPX(7)+1,TILETOPX(2)-1,
                            MAPFLAGENEMY,2,TILETOPX(6)-1,TILETOPX(2)-1,TILETOPX(7)+1,TILETOPX(2)-1,TILETOPX(7)+1,TILETOPX(3)+1,TILETOPX(6)-1,TILETOPX(3)+1,
                            
                            MAPFLAGENEMY,2,TILETOPX(7)+1,TILETOPX(1)+1,TILETOPX(2)-1,TILETOPX(1)+1,TILETOPX(2)-1,TILETOPX(0)-1,TILETOPX(7)+1,TILETOPX(0)-1,
                            MAPFLAGENEMY,2,TILETOPX(2)-1,TILETOPX(0)-1,TILETOPX(7)+1,TILETOPX(0)-1,TILETOPX(7)+1,TILETOPX(1)+1,TILETOPX(2)-1,TILETOPX(1)+1,
                            
                            MAPFLAGENEMY,2,TILETOPX(1)+1,TILETOPX(1)+1,TILETOPX(0)-1,TILETOPX(1)+1,TILETOPX(0)-1,TILETOPX(0)-1,TILETOPX(1)+1,TILETOPX(0)-1,
                            MAPFLAGENEMY,2,TILETOPX(0)-1,TILETOPX(0)-1,TILETOPX(1)+1,TILETOPX(0)-1,TILETOPX(1)+1,TILETOPX(1)+1,TILETOPX(0)-1,TILETOPX(1)+1,
                            
                            MAPFLAGENEMY,2,TILETOPX(1)+1,TILETOPX(7)+1,TILETOPX(1)+1,TILETOPX(2)-1,TILETOPX(0)-1,TILETOPX(2)-1,TILETOPX(0)-1,TILETOPX(7)+1,
                            MAPFLAGENEMY,2,TILETOPX(0)-1,TILETOPX(2)-1,TILETOPX(0)-1,TILETOPX(7)+1,TILETOPX(1)+1,TILETOPX(7)+1,TILETOPX(1)+1,TILETOPX(2)-1,
                            
                            MAPFLAGENEMY,2,TILETOPX(1)+1,TILETOPX(9)+1,TILETOPX(1)+1,TILETOPX(8)-1,TILETOPX(0)-1,TILETOPX(8)-1,TILETOPX(0)-1,TILETOPX(9)+1,
                            MAPFLAGENEMY,2,TILETOPX(0)-1,TILETOPX(8)-1,TILETOPX(0)-1,TILETOPX(9)+1,TILETOPX(1)+1,TILETOPX(9)+1,TILETOPX(1)+1,TILETOPX(8)-1,
                            
                            MAPFLAGEND};

const byte gamemap17[] PROGMEM = {3,
                            20,10,
                            0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,3,3,
                            0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,3,3,
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                            2,2,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,
                            2,2,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,
                            
                            TILETOPX(0) + (MAPTILESIZE / 2),TILETOPX(8) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,3,TILETOPX( 0),TILETOPX(7),TILETOPX( 0),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX( 1),TILETOPX(2),TILETOPX( 1),TILETOPX(7),
                            MAPFLAGENEMY,3,TILETOPX( 2),TILETOPX(7),TILETOPX( 2),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX( 3),TILETOPX(2),TILETOPX( 3),TILETOPX(7),
                            MAPFLAGENEMY,3,TILETOPX( 4),TILETOPX(7),TILETOPX( 4),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX( 5),TILETOPX(2),TILETOPX( 5),TILETOPX(7),
                            MAPFLAGENEMY,3,TILETOPX( 6),TILETOPX(7),TILETOPX( 6),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX( 7),TILETOPX(2),TILETOPX( 7),TILETOPX(7),
                            MAPFLAGENEMY,3,TILETOPX( 8),TILETOPX(7),TILETOPX( 8),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX( 9),TILETOPX(2),TILETOPX( 9),TILETOPX(7),
                            MAPFLAGENEMY,3,TILETOPX(10),TILETOPX(7),TILETOPX(10),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX(11),TILETOPX(2),TILETOPX(11),TILETOPX(7),
                            MAPFLAGENEMY,3,TILETOPX(12),TILETOPX(7),TILETOPX(12),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX(13),TILETOPX(2),TILETOPX(13),TILETOPX(7),
                            MAPFLAGENEMY,3,TILETOPX(14),TILETOPX(7),TILETOPX(14),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX(15),TILETOPX(2),TILETOPX(15),TILETOPX(7),
                            MAPFLAGENEMY,3,TILETOPX(16),TILETOPX(7),TILETOPX(16),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX(17),TILETOPX(2),TILETOPX(17),TILETOPX(7),
                            MAPFLAGENEMY,3,TILETOPX(18),TILETOPX(7),TILETOPX(18),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX(19),TILETOPX(2),TILETOPX(19),TILETOPX(7),
                            
                            MAPFLAGENEMY,3,TILETOPX(19),TILETOPX(2),TILETOPX( 0),TILETOPX(2),
                            MAPFLAGENEMY,3,TILETOPX( 0),TILETOPX(3),TILETOPX(19),TILETOPX(3),
                            MAPFLAGENEMY,3,TILETOPX(19),TILETOPX(4),TILETOPX( 0),TILETOPX(4),
                            MAPFLAGENEMY,3,TILETOPX( 0),TILETOPX(5),TILETOPX(19),TILETOPX(5),
                            MAPFLAGENEMY,3,TILETOPX(19),TILETOPX(6),TILETOPX( 0),TILETOPX(6),
                            MAPFLAGENEMY,3,TILETOPX( 0),TILETOPX(7),TILETOPX(19),TILETOPX(7),
                            
                            MAPFLAGEND};

const byte gamemap18[] PROGMEM = {2,
                            20,10,
                            0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,
                            0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,
                            0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,
                            0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,
                            0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,
                            0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,
                            0,0,0,0,0,0,0,1,1,2,2,1,1,0,0,0,0,0,0,0,
                            1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,
                            1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,
                            1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,
                            
                            TILETOPX(9) + (MAPTILESIZE / 2),TILETOPX(7) + (MAPTILESIZE / 2),
                            
                            MAPFLAGENEMY,2,TILETOPX(8),TILETOPX(7)+1,TILETOPX(8),TILETOPX(5)-1,
                            MAPFLAGENEMY,2,TILETOPX(7),TILETOPX(4)-1,TILETOPX(7),TILETOPX(6)+1,
                            MAPFLAGENEMY,2,TILETOPX(6),TILETOPX(5)+1,TILETOPX(6),TILETOPX(3)-1,
                            MAPFLAGENEMY,2,TILETOPX(5),TILETOPX(2)-1,TILETOPX(5),TILETOPX(4)+1,
                            MAPFLAGENEMY,2,TILETOPX(4),TILETOPX(3)+1,TILETOPX(4),TILETOPX(1)-1,
                            
                            MAPFLAGENEMY,2,TILETOPX(11),TILETOPX(5)-1,TILETOPX(11),TILETOPX(7)+1,
                            MAPFLAGENEMY,2,TILETOPX(12),TILETOPX(6)+1,TILETOPX(12),TILETOPX(4)-1,
                            MAPFLAGENEMY,2,TILETOPX(13),TILETOPX(3)-1,TILETOPX(13),TILETOPX(5)+1,
                            MAPFLAGENEMY,2,TILETOPX(14),TILETOPX(4)+1,TILETOPX(14),TILETOPX(2)-1,
                            MAPFLAGENEMY,2,TILETOPX(15),TILETOPX(1)-1,TILETOPX(15),TILETOPX(3)+1,
                            
                            MAPFLAGENEMY,2,TILETOPX( 0),TILETOPX(7),TILETOPX( 0),TILETOPX(9),
                            MAPFLAGENEMY,2,TILETOPX( 1),TILETOPX(9),TILETOPX( 1),TILETOPX(7),
                            MAPFLAGENEMY,2,TILETOPX( 2),TILETOPX(7),TILETOPX( 2),TILETOPX(9),
                            MAPFLAGENEMY,2,TILETOPX( 3),TILETOPX(9),TILETOPX( 3),TILETOPX(7),
                            MAPFLAGENEMY,2,TILETOPX( 4),TILETOPX(7),TILETOPX( 4),TILETOPX(9),
                            MAPFLAGENEMY,2,TILETOPX( 5),TILETOPX(9),TILETOPX( 5),TILETOPX(7),
                            MAPFLAGENEMY,2,TILETOPX( 6),TILETOPX(7),TILETOPX( 6),TILETOPX(9),
                            MAPFLAGENEMY,2,TILETOPX( 7),TILETOPX(9),TILETOPX( 7),TILETOPX(7),
                            
                            MAPFLAGENEMY,2,TILETOPX(12),TILETOPX(9),TILETOPX(12),TILETOPX(7),
                            MAPFLAGENEMY,2,TILETOPX(13),TILETOPX(7),TILETOPX(13),TILETOPX(9),
                            MAPFLAGENEMY,2,TILETOPX(14),TILETOPX(9),TILETOPX(14),TILETOPX(7),
                            MAPFLAGENEMY,2,TILETOPX(15),TILETOPX(7),TILETOPX(15),TILETOPX(9),
                            MAPFLAGENEMY,2,TILETOPX(16),TILETOPX(9),TILETOPX(16),TILETOPX(7),
                            MAPFLAGENEMY,2,TILETOPX(17),TILETOPX(7),TILETOPX(17),TILETOPX(9),
                            MAPFLAGENEMY,2,TILETOPX(18),TILETOPX(9),TILETOPX(18),TILETOPX(7),
                            MAPFLAGENEMY,2,TILETOPX(19),TILETOPX(7),TILETOPX(19),TILETOPX(9),
                            
                            MAPFLAGCOIN,TILETOPX(2) + (MAPTILESIZE / 2),TILETOPX(0) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX(16) + (MAPTILESIZE / 2),TILETOPX(0) + (MAPTILESIZE / 2),
                            MAPFLAGCOIN,TILETOPX(0),TILETOPX(8),
                            MAPFLAGCOIN,TILETOPX(19),TILETOPX(8),
                            
                            MAPFLAGEND};

const byte *gamemaps[] = {gamemap1,gamemap2,gamemap3,gamemap4,gamemap5,gamemap6,gamemap7,gamemap8,gamemap9,gamemap10,gamemap11,gamemap12,gamemap13,gamemap14,gamemap15,gamemap16,gamemap17,gamemap18};

const byte checkers[] PROGMEM = {MAPTILESIZE,MAPTILESIZE,0xAA,0x55,0xAA,0x55,0xAA,0x55};

#define NUMLEVELS 18

byte playerX;
byte playerY;
int mapX = MAPTILESIZE;
int mapY = MAPTILESIZE;
byte numEnemies;
byte numCoins;
bool dead = false;
bool frameskip = false;
int tries;
byte winTile;
bool potentialWin = false;
const byte * gamemap;
const byte * spawnpoints;
byte curLevelNum;
byte curSavePoint;
byte mapWidth;
byte mapHeight;

class Coin {
  byte x,y;
  byte have;
  public:
    Coin(byte cx,byte cy){
      x = cx;
      y = cy;
      have = 0;
    }
    void draw(){
      if(have > 0){
        return;
      }
      if(gb.collideRectRect(x,y,4,4,playerX,playerY,4,4)){
        have = 1;
        gb.sound.playTick();
      }
      int drawX = x + mapX;
      int drawY = y + mapY;
      if(drawX > 86 || drawY > 68 || drawX < -4 || drawY < -4){
        return;
      }
      gb.display.drawRoundRect(drawX,drawY,4,4,1);
    }
    void reset(){
      if(have!=2){
        have = 0;
      }
    }
    void stick(){
      if(have==1){
        have = 2;
      }
    }
    bool doHave(){
      return have>0;
    }
};
Coin *coins[70];

class Enemy {
  int x,y;
  byte s;
  const byte * points;
  const byte * startPoints;
  byte nextPoint;
  public:
    Enemy(byte bs,const byte * ps){
      x = pgm_read_byte(ps);
      y = pgm_read_byte(ps + 1);
      s = bs;
      points = ps;
      startPoints = ps;
      nextPoint = 0;
    }
    void update(){
      if(s == 0){ // no need to update as we aren't moving
        return;
      }
      int nx = pgm_read_byte(points);
      int ny = pgm_read_byte(points+1);
      if(nx > x){
        x += s;
        if(nx < x){
          x = nx;
        }
      }
      if(nx < x){
        x -= s;
        if(nx > x){
          x = nx;
        }
      }
      
      if(ny > y){
        y += s;
        if(ny < y){
          y = ny;
        }
      }
      if(ny < y){
        y -= s;
        if(ny > y){
          y = ny;
        }
      }
      if(nx==x && ny==y){
        points += 2;
        byte tmp = pgm_read_byte(points);
        if(tmp == MAPFLAGENEMY || tmp == MAPFLAGCOIN || tmp == MAPFLAGEND){
          points = startPoints;
        }
      }
    }
    void draw(){
      if(gb.collideRectRect(x,y,4,4,playerX,playerY,4,4)){
        dead = true;
      }
      int drawX = x + mapX;
      int drawY = y + mapY;
      if(drawX > 86 || drawY > 68 || drawX < -4 || drawY < -4){
        return;
      }
      gb.display.fillRect(drawX,drawY + 1,4,2);
      gb.display.fillRect(drawX + 1,drawY,2,4);
    }
};

Enemy *enemies[42];

void setup() {
  gb.begin();
  doTitleScreen(true);
}
void doTitleScreen(bool doTitle){
  do{
    destroyMap();
    if(doTitle){
      gb.titleScreen(F("Worlds Hardest Game")); // 64x30 px
      gb.battery.show = false;
      gb.setFrameRate(30);
      gb.display.persistence = false;
    }
    doTitle = true;
  }while(!doMainMenu());
}

const char menuLevel1[] PROGMEM = "Level 1";
const char menuLevel2[] PROGMEM = "Level 2";
const char menuLevel3[] PROGMEM = "Level 3";
const char menuLevel4[] PROGMEM = "Level 4";
const char menuLevel5[] PROGMEM = "Level 5";
const char menuLevel6[] PROGMEM = "Level 6";
const char menuLevel7[] PROGMEM = "Level 7";
const char menuLevel8[] PROGMEM = "Level 8";
const char menuLevel9[] PROGMEM = "Level 9";
const char menuLevel10[] PROGMEM = "Level 10";
const char menuLevel11[] PROGMEM = "Level 11";
const char menuLevel12[] PROGMEM = "Level 12";
const char menuLevel13[] PROGMEM = "Level 13";
const char menuLevel14[] PROGMEM = "Level 14";
const char menuLevel15[] PROGMEM = "Level 15";
const char menuLevel16[] PROGMEM = "Level 16";
const char menuLevel17[] PROGMEM = "Level 17";
const char menuLevel18[] PROGMEM = "Level 18";
const char menuTitleScreen[] PROGMEM = "Title Screen";

const char* const mainmenu[NUMLEVELS+1] PROGMEM = {
  menuLevel1,
  menuLevel2,
  menuLevel3,
  menuLevel4,
  menuLevel5,
  menuLevel6,
  menuLevel7,
  menuLevel8,
  menuLevel9,
  menuLevel10,
  menuLevel11,
  menuLevel12,
  menuLevel13,
  menuLevel14,
  menuLevel15,
  menuLevel16,
  menuLevel17,
  menuLevel18,
  menuTitleScreen
};

bool doMainMenu(){
  byte ret = gb.menu(mainmenu,NUMLEVELS+1);
  tries = 0;
  if(ret >= 0 && ret <= NUMLEVELS-1){
    curLevelNum = ret;
    loadMap();
    return true;
  }
  return false;
}
void loop() {
  if(gb.update()){
    potentialWin = false;
    if(gb.buttons.repeat(BTN_UP,0)){
      playerY--;
      if(getTileAtPos(0,0)==0 || getTileAtPos(3,0)==0){
        playerY++;
      }
    }
    if(gb.buttons.repeat(BTN_DOWN,0)){
      playerY++;
      if(getTileAtPos(0,3)==0 || getTileAtPos(3,3)==0){
        playerY--;
      }
    }
    if(gb.buttons.repeat(BTN_LEFT,0)){
      playerX--;
      if(getTileAtPos(0,0)==0 || getTileAtPos(0,3)==0){
        playerX++;
      }
    }
    if(gb.buttons.repeat(BTN_RIGHT,0)){
      playerX++;
      if(getTileAtPos(3,0)==0 || getTileAtPos(3,3)==0){
        playerX--;
      }
    }
    drawWorld();
    if(dead){
      tries++;
      gb.sound.playCancel();
      resetPlayer();
    }else if(potentialWin){
      bool win = true;
      for(byte i = 0;i < numCoins;i++){
        win &= coins[i]->doHave();
      }
      if(win){
        gb.sound.playOK();
        gb.popup(F("Woooo"),30);
        destroyMap();
        if(++curLevelNum >= NUMLEVELS){
          doTitleScreen(false);
        }else{
          loadMap();
        }
      }
    }
    if(gb.buttons.pressed(BTN_C)) {
      doTitleScreen(false);
    }
  }
}
void loadMap(){
  gamemap = gamemaps[curLevelNum];
  numEnemies = 0;
  numCoins = 0;
  mapHeight = pgm_read_byte(gamemap+MAPHEADER-1);
  mapWidth = pgm_read_byte(gamemap+MAPHEADER-2);
  unsigned int i = MAPHEADER + (mapWidth * mapHeight);
  
  spawnpoints = gamemap+i;
  
  while(pgm_read_byte(gamemap+i)!=MAPFLAGEND){
    byte flag = pgm_read_byte(gamemap+(i++)); // we want to increase i AFTER we check in either case
    if(flag==MAPFLAGENEMY){
      enemies[numEnemies++] = new Enemy(pgm_read_byte(gamemap+(i++)),gamemap+i);
    }else if(flag==MAPFLAGCOIN){
      coins[numCoins++] = new Coin(pgm_read_byte(gamemap+(i++)),pgm_read_byte(gamemap+i));
    }
  }
  winTile = pgm_read_byte(gamemap+0);
  curSavePoint = 2;
  
  resetPlayer();
}
void destroyMap(){
  for(byte i = 0;i < numEnemies;i++){
    delete enemies[i];
  }
  for(byte i = 0;i < numCoins;i++){
    delete coins[i];
  }
  numEnemies = 0;
  numCoins = 0;
}
void resetPlayer(){
  dead = false;
  playerX = pgm_read_byte(spawnpoints+0);
  playerY = pgm_read_byte(spawnpoints+1);
  for(byte i = 0;i < numCoins;i++){
    coins[i]->reset();
  }
}

byte getTileAtPos(byte xoffset,byte yoffset){
  if(playerY+yoffset < 0 || playerX+xoffset < 0 || playerY+yoffset >= mapHeight*MAPTILESIZE || playerX+xoffset >= mapWidth*MAPTILESIZE){
    return 0;
  }
  byte tile = pgm_read_byte(gamemap+(((playerY+yoffset) / MAPTILESIZE)*mapWidth+((playerX+xoffset) / MAPTILESIZE)+MAPHEADER));
  potentialWin |= tile==winTile;
  if(tile > curSavePoint && !potentialWin){
    spawnpoints+=2*(tile - curSavePoint);
    curSavePoint += tile - curSavePoint;
    for(byte i = 0;i < numCoins;i++){
      coins[i]->stick();
    }
  }
  return tile;
}
void drawWorld(){
  if(playerX + mapX < 20){
    mapX++;
  }
  if(playerX + mapX > 64){
    mapX--;
  }
  if(playerY + mapY < 10){
    mapY++;
  }
  if(playerY + mapY > 38){
    mapY--;
  }
  gb.display.fillScreen(BLACK);
  gb.display.setColor(WHITE);
  for(byte y = 0;y < mapHeight;y++){
    for(byte x = 0;x < mapWidth;x++){
      byte tile = pgm_read_byte(gamemap+(y*mapWidth+x+MAPHEADER));
      int drawX = x*MAPTILESIZE+mapX;
      int drawY = y*MAPTILESIZE+mapY;
      if(drawX > 86 || drawY > 68 || drawX < -4 || drawY < -4){
        continue;
      }
      if(tile==1){
        gb.display.fillRect(drawX,drawY,MAPTILESIZE,MAPTILESIZE);
      }else if(tile!=0){
        gb.display.drawBitmap(drawX,drawY,(const byte*)checkers,NOROT,NOFLIP);
      }
    }
  }
  gb.display.fillRect(playerX + mapX + 1,playerY + mapY + 1,2,2);
  gb.display.setColor(BLACK);
  gb.display.drawRect(playerX + mapX,playerY + mapY,4,4);
  for(byte i = 0;i < numEnemies;i++){
    if(!frameskip){
      enemies[i]->update();
    }
    enemies[i]->draw();
  }
  for(byte i = 0;i < numCoins;i++){
    coins[i]->draw();
  }
  gb.display.cursorX = 1;
  gb.display.cursorY = 1;
  gb.display.setColor(WHITE,BLACK);
  gb.display.print(tries);
  frameskip = !frameskip;
}
