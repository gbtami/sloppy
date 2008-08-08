#ifndef PERFT_H
#define PERFT_H

#include "sloppy.h"


#ifdef USE_THREADS
/* Destroy all pthread mutexes and condition variables.  */
extern void thread_cleanup(void);
#endif /* USE_THREADS */

/* Test Sloppy's move generation, make_move(), hash table and performance.
   This function calculates the number of nodes in a minimax search of the
   current board position to depth <depth>.
   If <divide> is true, a node count for each root move is also displayed.  */
extern U64 perft_root(Board *board, int depth, bool divide);

#endif /* PERFT_H */

