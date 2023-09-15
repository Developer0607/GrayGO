/**********
 * Game Board
 * GrayGO 0.1
***********/

//DEBUG
#include<cstdio>
void err(){
    printf("GEOMETRY MODOLE ERROR!\n");
}

#define WHITE 0
#define BLACK 1

class GAME_BOARD{
    public:
        int size = 19;
        char board[19][19];
};

struct STONE{
    int x;int y;
    bool color; //0=White, 1=Black
};

struct PART{
    bool color;
    int tot = 0;
    STONE* lpStones [361];
};

struct COMBINE{
    bool color;
    int tot = 0;
    PART* lpParts [361];
};

class GAME_ANALYSE{
    public:
        GAME_BOARD Board;
        int Num = 0;
        COMBINE white[361];
        COMBINE black[361];
        PART wp[361];
        PART bp[361];
        STONE ws[1000];
        STONE bs[1000];
        int whiteTot = 0;
        int blackTot = 0;
        int wptot    = 0;
        int bptot    = 0;
        int wstot    = 0;
        int bstot    = 0;

        bool JIE = false;
        int JIE_x; int JIE_y;


        int partmap[19][19];
        int combmap[19][19];

        //Functions
        void wpartmerge(int x, int y){
            for(int i = 0; i <= wp[y].tot; i ++){
                wp[x].tot ++;
                wp[x].lpStones[wp[x].tot] = wp[y].lpStones[i];
                partmap[(*(wp[x].lpStones[wp[x].tot])).x][(*(wp[x].lpStones[wp[x].tot])).y] = x;
            }
            wp[y].tot = 0;
        }
        void bpartmerge(int x, int y){
            for(int i = 0; i <= bp[y].tot; i ++){
                bp[x].tot ++;
                bp[x].lpStones[bp[x].tot] = bp[y].lpStones[i];
                partmap[(*(bp[x].lpStones[bp[x].tot])).x][(*(bp[x].lpStones[bp[x].tot])).y] = x;
            }
            bp[y].tot = 0;
        }
        void wcombmerge(int x, int y){
            for(int i = 0; i <= white[y].tot; i ++){
                white[x].tot ++;
                white[x].lpParts[white[x].tot] = white[y].lpParts[i];
                for(int j = 0; j <= (*(white[x].lpParts[white[x].tot])).tot; j ++)
                combmap[(*(*(white[x].lpParts[white[x].tot])).lpStones[j]).x][(*(*(white[x].lpParts[white[x].tot])).lpStones[j]).y] = x;
            }
            white[y].tot = 0;
        }
        void bcombmerge(int x, int y){
            for(int i = 0; i <= black[y].tot; i ++){
                black[x].tot ++;
                black[x].lpParts[black[x].tot] = black[y].lpParts[i];
                for(int j = 0; j <= (*(black[x].lpParts[black[x].tot])).tot; j ++)
                combmap[(*(*(black[x].lpParts[black[x].tot])).lpStones[j]).x][(*(*(black[x].lpParts[black[x].tot])).lpStones[j]).y] = x;
            }
            black[y].tot = 0;
        }
        void parting(int x, int y){
            if(Board.board[x][y] == -1){
                //DEBUG
                err();
            }
            if(Board.board[x-1][y] == Board.board[x][y]){
                if(Board.board[x][y] == WHITE){
                    wpartmerge(partmap[x][y],partmap[x-1][y]);
                }
                if(Board.board[x][y] == BLACK){
                    bpartmerge(partmap[x][y],partmap[x-1][y]);
                }
            }
            if(Board.board[x+1][y] == Board.board[x][y]){
                if(Board.board[x][y] == WHITE){
                    wpartmerge(partmap[x][y],partmap[x+1][y]);
                }
                if(Board.board[x][y] == BLACK){
                    bpartmerge(partmap[x][y],partmap[x+1][y]);
                }
            }
            if(Board.board[x][y-1] == Board.board[x][y]){
                if(Board.board[x][y] == WHITE){
                    wpartmerge(partmap[x][y],partmap[x][y-1]);
                }
                if(Board.board[x][y] == BLACK){
                    bpartmerge(partmap[x][y],partmap[x][y-1]);
                }
            }
            if(Board.board[x][y+1] == Board.board[x][y]){
                if(Board.board[x][y] == WHITE){
                    wpartmerge(partmap[x][y],partmap[x][y+1]);
                }
                if(Board.board[x][y] == BLACK){
                    bpartmerge(partmap[x][y],partmap[x][y+1]);
                }
            }
        }
        void putstone(bool COLOR, int x, int y){
            if(COLOR == WHITE){
                wstot++;
                ws[wstot].color = WHITE;
                ws[wstot].x     = x;
                ws[wstot].y     = y;
                parting(x,y);
            }
            if(COLOR == BLACK){
                wstot++;
                ws[wstot].color = WHITE;
                ws[wstot].x     = x;
                ws[wstot].y     = y;
                parting(x,y);
            }
        }

};

/*class GAME_CASE{
    public:
        GAME_BOARD board;
        bool JIE = false;
        int JIE_x; int JIE_y;
        
};*/