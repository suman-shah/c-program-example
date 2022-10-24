// Tower of Hanoi:
// --------------

// Tower of Hanoi is one study case we come across while learning Recursion.Tower of Hanoi is a simple game in which you are given
// a task to move 'n' no of disks sized from smaller to bigger from top to bottom from Tower A to Tower C using an additional Tower B.
// This game consists of few rules :

// - You can only pick up single disk at a time.
// - You should not place a bigger disk on the smaller disk.
// - The end Tower(say Tower C) should contain all the disks in the same order as it was in Tower A at the beginning of the game.

// To solve this problem, we divide it into small sub problem which has to do the same task repeatively.
// Thus, it can be implemented through a recursive function.

// Let's see a few cases,

// Case 1: There only a single Disk on Tower A
// ------
// Since there is only a single on Tower A, we just place it onto Tower B as it is.

// Case 2: There are 2 Disks on Tower A.
// ------
// It's not as simple as Case 1 but it still an easy solution, we just have to place the smallest disk to Tower B, then move the
// Largest Disk to Tower C and then Finally from Tower B to Tower C. Thus, we have moved the Disk from Tower A to Tower C.

// Case 3: There are 3 Disks on Tower A.
// ------
// Now. from this case the task gets even complex. So, How do we move all the Disks on Tower A to Tower C by following all the rules ?
// So, to Solve this case, we have to break down the problem into sub-problem like Moving the Top most 2 disks to Tower B and then
// moving the Last/Largest Disk to Tower C & at last the 2 Disks from Tower B to Tower C.

// So, how do we implement the case 3 we just discussed ? and as the rules say we can move only one disk at a time, then how can we shift
// Top most of the 2 Disks from Tower A to Tower B & Tower B to Tower C ? These might be the question you might having right now.

// As I have told you that we divide the larger problem into sub-problem, we divide the Moving 3 disks into moving 2 disk + moving 1 disk task,
// Then we further break down the moving 2 disks problem into moving 1 disk + moving 1 disk task. But only thing which changes is the source
// and destination Tower.

// Try constructing the recursive tree diagram for even better understanding on the recursive calls that are helps us solve this puzzle.

#include <stdio.h>

// Towers of Hanoi logic
void TOH(int n_disks, char Tower_A, char Tower_B, char Tower_C)
{
    if (n_disks > 0)
    {
        // first we make all n-1 disk are moved to Tower B using Tower C.
        TOH(n_disks - 1, Tower_A, Tower_C, Tower_B);

        // Then we move the Largest/Last Disk from Tower A to Tower C.
        printf("Move Disk %d: from Tower %c -> Tower %c\n", n_disks, Tower_A, Tower_C);

        // Finally we move all n-1 disk to Tower B using Tower C using Tower A.
        TOH(n_disks - 1, Tower_B, Tower_A, Tower_C);
    }

    return;
}

// Driver Program
int main(void)
{
    int no_of_disks = 3;
    char Tower_A = 'A', Tower_B = 'B', Tower_C = 'C';
    TOH(no_of_disks, Tower_A, Tower_B, Tower_C);
    return 0;
}

// Output:
// -------

// Move Disk 1: from Tower A -> Tower C
// Move Disk 2: from Tower A -> Tower B
// Move Disk 1: from Tower C -> Tower B
// Move Disk 3: from Tower A -> Tower C
// Move Disk 1: from Tower B -> Tower A
// Move Disk 2: from Tower B -> Tower C
// Move Disk 1: from Tower A -> Tower C