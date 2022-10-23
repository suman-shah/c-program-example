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