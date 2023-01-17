import numpy as np
import time, itertools
from multiprocessing import Pool
from generator import list_generator

# global COUNT
# COUNT = 0

# pile1 = [2,1,3,6,5,8]
# pile1 = [1000, 757, 680, 607, 455, 408, 570, 173, 595, 402, 36, 99]
# pile1 = list_generator(1,100)
# pile1 = [82, 51, 77, 3, 92, 2, 49, 21, 13, 66, 71, 19, 55, 4, 40, 81, 32, 14, 45, 27, 42, 74, 43, 62, 26, 57, 7, 24, 99, 88, 90, 33, 5, 52, 6, 29, 69, 12, 31, 100, 46, 83, 25, 17, 30, 10, 63, 39, 36, 61, 20, 91, 48, 15, 54, 75, 96, 60, 34, 73, 44, 93, 35, 41, 79, 16, 95, 84, 50, 53, 18, 65, 28, 76, 58, 11, 38, 23, 85, 78, 72, 70, 80, 59, 8, 87, 47, 94, 1, 68, 89, 64, 67, 22, 56, 97, 86, 37, 9, 98]

def print_command(cmd: str) -> None:
    global COUNT
    COUNT += 1
    # print(cmd)
    # return cmd

def push_b(pile: list, nbr: int) -> list:
    pile.insert(0, nbr)
    print_command("pb")
    return pile

def push_a(pile: list, nbr: int) -> list:
    pile.insert(0, nbr)
    print_command("pa")
    return pile

def rotate_b(pile: list) -> list:
    print_command("rb")
    return list(np.roll(pile, -1))

def rotate_a(pile: list) -> list:
    print_command("ra")
    return list(np.roll(pile, -1))

def reverse_rotate_a(pile: list) -> list:
    print_command("rra")
    return list(np.roll(pile, 1))

def reverse_rotate_b(pile: list) -> list:
    print_command("rrb")
    return list(np.roll(pile, 1))

def swap_a(pile: list) -> None:
    t = pile[0]
    pile[0] = pile[1]
    pile[1] = t
    print_command('sa')

def rotate_a_and_b(pilea : list, pileb : list):
    if len(pilea) > 1 and len(pileb) > 1:
        pilea = list(np.roll(pilea, -1))
        pileb = list(np.roll(pileb, -1))
        print_command("rr")
        return pilea, pileb

def reverse_rotate_a_and_b(pilea: list, pileb: list):
    if len(pilea) > 1 and len(pileb) > 1:
        pilea = list(np.roll(pilea, 1))
        pileb = list(np.roll(pileb, 1))
        print_command("rrr")
        return pilea, pileb

def small_sort(pile: list) -> list:
    # print("Debut de sort three")
    fst, scd, trd = pile[0], pile[1], pile[2]

    if (fst < scd) and (scd > trd) and (fst < trd):
        pile = reverse_rotate_a(pile)
        swap_a(pile)
    elif (fst < scd) and (scd > trd) and (fst > trd):
        pile = reverse_rotate_a(pile)
    elif (fst > scd) and (scd < trd) and (fst > trd):
        pile = rotate_a(pile)
    elif (fst > scd) and (scd > trd):
        swap_a(pile)
        pile = reverse_rotate_a(pile)
    else:
        swap_a(pile)
    return pile

def replace_pile(pilea:list):
    m = min(pilea)
    if (pilea[0] != m):
        i = pilea.index(m)
        if (i <= (len(pilea) // 2)):
            while pilea[0] != m:
                pilea = rotate_a(pilea)
        else:
            while pilea[0] != m:
                pilea = reverse_rotate_a(pilea)
    return pilea

def rr_rra(pilea:list, pileb:list, pos_a:int, i:int):
    if pos_a <= (len(pilea) // 2):
        while i <= (pos_a - 1):
            pilea = rotate_a(pilea)
            i += 1
    else:
        while i < (len(pilea) - pos_a):
            pilea = reverse_rotate_a(pilea)
            i += 1

    return pilea, pileb

def check_for_opti(pilea:list, pileb:list, pos_a:int, pos_b:int):
    i = 0

    if ((pos_a <= (len(pilea) // 2)) and (pos_b <= (len(pileb) // 2))):
        while (i <= (pos_a - 1)) and (i <= (pos_b - 1)):
            pilea, pileb = rotate_a_and_b(pilea, pileb)
            i += 1

    if ((pos_a > (len(pilea) // 2)) and (pos_b > (len(pileb) // 2))):
        while (i < (len(pilea) - pos_a)) and (i < (len(pileb) - pos_b)):
            pilea, pileb = reverse_rotate_a_and_b(pilea, pileb)
            i += 1

    return i, pilea, pileb

def pos_to_place(pile:list, elem: int) -> int:
    mininum = min(pile)
    maximum = max(pile)
    
    if elem > maximum or elem < mininum:
        return pile.index(mininum)

    for c,i in enumerate(pile):
        prev = pile[c - 1]
        if prev < elem < i:
            return c

    return 0

def count_move(pilea:list, pileb:list, elem:int) -> int:
    count_moves = 1
    index = pileb.index(elem)

    if (index > 1 and index > (len(pileb) // 2)):
        count_moves += len(pileb) - index - 1
    elif (index > 1 and index <= (len(pileb) // 2)):
        count_moves += (index - 1)
    
    index = pos_to_place(pilea, elem)
    if (index > 1 and index > (len(pilea) // 2)):
        count_moves += len(pilea) - index - 1
    elif (index > 1 and index <= (len(pilea) // 2)):
        count_moves += (index - 1)

    return count_moves

def get_best_move(pilea: list, pileb: list):
    best_move_elem = pileb[0]
    best_move_count = count_move(pilea, pileb, best_move_elem)
    for i in pileb:
        move_count = count_move(pilea, pileb, i)
        # print(f"move_count : {move_count} -> {i}")
        if move_count < best_move_count:
            best_move_count = move_count
            best_move_elem = i
    # print(f"best move : {best_move_elem} avec un cout de {best_move_count}")
    return best_move_elem

def insertion_sort(pilea:list, pileb:list, elem:int):
    pos_a = pos_to_place(pilea, elem)
    pos_b = pileb.index(elem)

    i, pilea, pileb = check_for_opti(pilea, pileb, pos_a, pos_b)

    while (pileb[0] != elem):
        if pos_b <= (len(pileb) // 2):
            pileb = rotate_b(pileb)
        else:
            pileb = reverse_rotate_b(pileb)
    pilea, pileb = rr_rra(pilea, pileb, pos_a, i)
    pilea = push_a(pilea, pileb[0])
    pileb.pop(0)
    return pilea, pileb

def inner(pile: list, q1: int, q2: int):
    for i in pile:
        if q1 <= i <= q2:
            return True
    return False

def push_swap(pile:list):
    global COUNT
    COUNT = 0
    pile1 = pile
    pile2 = list()

    array = pile1.copy()
    array.sort()

    if (len(pile1) % 2 == 0):
        medianne = len(pile1) // 2
    else:
        medianne = (len(pile1) + 1) // 2
    if medianne % 2 == 0:
        quart1 = medianne // 2
    else:
        quart1 =  (medianne + 1) // 2
    quart2 = medianne + quart1
    ref = array[medianne - 1]
    # q1 = array[quart1]
    q1 = 0
    # q2 = array[quart2]
    q2 = 0
    # print(f"coucou on est au début ma ref est : {ref} {len(pile1)}")
    # print(f"q1 {q1} q2 {q2}")
    
    while inner(pile1, q1, q2) and len(pile1) > 8:
        # print(pile1)
        if pile1[0] >= q1 and pile1[0] <= ref:
            pile2 = push_b(pile2, pile1[0])
            pile2 = rotate_b(pile2)
            pile1.pop(0)
            continue
        if pile1[0] <= q2 and pile1[0] >= ref:
            pile2 = push_b(pile2, pile1[0])
            pile1.pop(0)
            continue
        else:
            pile1 = rotate_a(pile1)

    while len(pile1) > 3:
        pile2 = push_b(pile2, pile1[0])
        if pile1[0] < ref:
            pile2 = rotate_b(pile2)
        pile1.pop(0)

    tmp = pile1.copy()
    tmp.sort()
    # print(pile1)
    if pile1 != tmp:
        pile1 = small_sort(pile1)

    while pile2:
        pile1, pile2 = insertion_sort(pile1, pile2, get_best_move(pile1, pile2))

    pile1 = replace_pile(pile1)

    # print(f"pile 1 : ")
    # print(f"pile 2 : {pile2}")
    # print(f"count : {COUNT}")
    # print(f"Iteration n°{i}")
    
    assert pile1 == array, "Not Sorted"
    # print("Sorted")
    print(COUNT)
    return COUNT

if __name__ == "__main__":
    st = time.time()
    COUNT = 0
    nb = 2
    liste = [1, 2]
    resultat = list(itertools.permutations(liste))
    random = list(map(list, resultat))
    # push_swap_bis(list_generator(1,100))
    # for _ in range(nb):
        # random.append(list_generator(1,100))
    res = list()
    with Pool() as pool:
        res = pool.map(push_swap, random)
    # t = "5 16 14 87 70 20 80 3 79 36 74 17 48 51 13 72 4 68 22 10 44 19 60 32 64 42 94 43 75 92 47 11 62 100 52 73 54 37 30 93 69 95 50 65 99 59 91 38 34 53 76 97 78 24 25 46 98 7 39 86 33 1 82 41 26 28 45 77 81 9 88 35 66 89 55 21 31 84 90 2 85 6 71 23 63 49 15 61 18 40 8 12 57 56 29 27 67 58 83 96".split()
    # res.append(push_swap(list(map(int, t))))
    # for i in random:
        # res.append(push_swap(i))
    elapsed_time = time.time() - st
    # with open("log.txt", 'a', encoding="utf-8") as f:
        # for i in range(nb):
            # f.write(f"{res[i]} :\n {random[i]}\n\n")
    print("<--- --------- --->")
    print(f"Sur {nb} tests :")
    print(f"# Min ->        {min(res)}")
    print(random[res.index(min(res))])
    print(f"# Max ->        {max(res)}")
    print(random[res.index(max(res))])
    print(f"# Moyenne ->    {sum(res) / nb}")
    print(f"Temps d'execution : ", time.strftime("%H:%M:%S", time.gmtime(elapsed_time)))