#ifndef BOOK_H
#define BOOK_H

#include "sloppy.h"
#include "avltree.h"

#define BOOK_FILE "book.bin"


/* Returns true if <filename> exists.  */
extern bool book_exists(const char *filename);

/* Read an opening book file and store its positions in an AVL tree.
   Returns 0 if successfull.  */
extern int book_to_tree(const char *filename, AvlNode **tree);

/* Displays a list of the available book moves.  */
extern void print_book(Board *board, AvlNode *book);

/* Probe the book (already in RAM) for a good move to be played.
   Returns NULLMOVE if no book moves with a score above 0 are found.
   If <show_book> is true, a list of available moves is displayed.  */
extern U32 get_book_move(Board *board, bool show_book, AvlNode *book);

/* Store a position in an AVL tree.
   Returns true if the position is new.  */
extern bool save_book_pos(U64 key, int points, AvlNode **tree);

/* Write an AVL tree to a file (the opening book), then clear the tree.
   Returns 0 if successfull.  */
extern int write_book(const char *filename, AvlNode *tree);

/* Store the positions of a played game (stored in <board>) in an AVL tree.
   <winner> is either WHITE or BLACK.  */
extern void book_learn(Board *board, int winner, AvlNode **tree);

#endif /* BOOK_H */

