//
// Created by yume on 30/09/22.
//

#include <stdio.h>
#include <malloc.h>
#include "td3.h"

void
td3(void) {
    printf("TD3\n");
    int array[5] = {0, 2, 4, 6, 8};
    update_sorted_array(array, 5, 3, 3);
    printf("\n");
    int array2[5] = {6, 3, 4, 2, 1};
    selection_sort(array2, 5);
    for (int i = 0; i < 5; ++i) {
        printf("%d ", array2[i]);
    }
}

// ----------------------------------- Ex 3.1 -----------------------------------
/*
 * Ex 3.1
 * 1. Compléxité du tri par insertion
 * -> O(n²) Worst case
 * -> O(n) Best case
 * -> O(n²) Average case
 * Explications :
 * - Le pire cas est quand le tableau est inversé, donc on doit faire n comparaisons pour chaque élément
 * - Le meilleur cas est quand le tableau est déjà trié, donc on ne fait aucune comparaison
 * - Le cas moyen est quand le tableau est mélangé, donc on fait n comparaisons pour chaque élément
 * Le tri par insertion est donc O(n²) dans 99% des cas. Il est donc très lent.
 * On peut tout de même l'utiliser pour insérer un élément dans un tableau trié.
 * Il est aussi utilisé pour trier des petits tableaux.
 */
/*
 * Ex 3.1 2)
 * On modifie une valeur du tableau trié. On doit alors rétablir l'ordre du tableau.
 * On peut utiliser le tri par insertion pour cela.
 * Pseudo code :
 *
 * fn update_sorted_array(array, size, value, index) {
 *  // 1. On insère la valeur à la position index
 *  array[index] <- value
 *  // On vérifie si l'ordre est respecté à gauche
 *  tant que (index > 1 et array[index] < array[index-1]) {
 *      // On échange les valeurs
 *      tmp <- array[index]
 *      array[index] <- array[index-1]
 *      array[index-1] <- tmp
 *      // On décrémente l'index
 *      index <- index - 1
 *      }
 *  // On vérifie si l'ordre est respecté à droite
 *  tant que (index < size-1 et array[index] > array[index+1]) {
 *    // On échange les valeurs
 *    tmp <- array[index]
 *    array[index] <- array[index+1]
 *    array[index+1] <- tmp
 *    // On incrémente l'index
 *    index <- index + 1
 *    }
 * }
 * Compléxité :
 *    -> O(n) dans le pire cas (si on doit décaler tous les éléments)
 *    -> O(1) dans le meilleur cas (si on insère à la bonne place)
 *    -> O(n) dans le cas moyen
 */
void
update_sorted_array(int* array, int size, int value, int index) {
    printf("Exercice 3.1\n");
    printf("Insertion de %d à l'index %d\n", value, index);
    // We change the value at the given index to the given value and we shift the other values to sort the array
    array[index] = value;
    // Is the left value greater than the value ?
    while (index > 0 && array[index - 1] > array[index]) {
        // We swap the values
        int tmp = array[index];
        array[index] = array[index - 1];
        array[index - 1] = tmp;
        --index;
    }

    // Is the right value smaller than the value ?
    while (index < size - 1 && array[index + 1] < array[index]) {
        // We swap the values
        int tmp = array[index];
        array[index] = array[index + 1];
        array[index + 1] = tmp;
        ++index;
    }

    // We print the array
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
}

// ----------------------------------- Ex 3.2 -----------------------------------
/*
 * Ex 3.2
 *  Pseudo code :
 *  fn selection_sort(array, size) {
 *    // On parcourt le tableau
 *    pour i allant de 1 à size {
 *      // On initialise l'index de la plus petite valeur à i
 *      min_index <- i
 *      // On parcourt le tableau à partir de i+1
 *      pour j allant de i+1 à size {
 *          // Si la valeur à l'index j est plus petite que la valeur à l'index min_index
 *          si (array[j] < array[min_index]) {
 *          // On met à jour l'index de la plus petite valeur
 *          min_index <- j
 *          }
 *      }
 *      // On échange les valeurs
 *      tmp <- array[i]
 *      array[i] <- array[min_index]
 *      array[min_index] <- tmp
 *   }
 *  }
 *  Compléxité :
 *  -> O(n²) dans le pire cas
 *  -> O(n²) dans le meilleur cas
 *  -> O(n²) dans le cas moyen
 *  Explications :
 *  On doit faire n comparaisons pour chaque élément, donc O(n²)

 */
void
selection_sort(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        int min = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        int tmp = array[i];
        array[i] = array[min];
        array[min] = tmp;
    }
}

// ----------------------------------- Ex 3.3 -----------------------------------
/*
 * Ex 3.3
 * Pseudo code :
 *  fn merge_array(array1, size1, array2, size2) {
 *    // On crée un nouveau tableau de taille size1 + size2
 *    new_array <- tableau de taille size1 + size2
 *    // On initialise les index des deux tableaux
 *    i <- 1 // Index du premier tableau (array1)
 *    j <- 1 // Index du deuxième tableau (array2)
 *    // On parcourt le nouveau tableau
 *    pour k allant de 1 à size1 + size2 {
 *    // Si on a parcouru tous les éléments du premier tableau
 *    si (i > size1) {
 *    // On ajoute les éléments du second tableau
 *    new_array[k] <- array2[j] // On ajoute l'élément à l'index j du tableau array2
 *    j <- j + 1 // On incrémente l'index du second tableau
 *    }
 *    // Si on a parcouru tous les éléments du second tableau
 *    si (j > size2) {
 *    // On ajoute les éléments du premier tableau
 *    new_array[k] <- array1[i] // On ajoute l'élément à l'index i du tableau array1
 *    i <- i + 1 // On incrémente l'index du premier tableau
 *    }
 *    // Si l'élément du premier tableau est plus petit que l'élément du second tableau
 *    si (array1[i] < array2[j] et i <= size1 et j <= size2)) {
 *    // On ajoute l'élément du premier tableau
 *    new_array[k] <- array1[i] // On ajoute l'élément à l'index i du tableau array1
 *    i <- i + 1 // On incrémente l'index du premier tableau
 *    }
 *    // Sinon
 *    sinon {
 *    // On ajoute l'élément du second tableau
 *    new_array[k] <- array2[j] // On ajoute l'élément à l'index j du tableau array2
 *    j <- j + 1 // On incrémente l'index du second tableau
 *    }
 *   }
 *  }
 *  Compléxité :
 *  -> O(n) dans le pire cas
 *  -> O(n) dans le meilleur cas
 *  -> O(n) dans le cas moyen
 *  Explications :
 *  On parcourt les deux tableaux une seule fois, donc O(n)
 *
 *  Merge sort :
 *  Pseudo code :
 *  fn merge_sort(array, size) {
 *  // Si la taille du tableau est inférieur à 1 | Cas de base de la récursivité
 *  si (size < 1) {
 *  // On retourne le tableau
 *  return array
 *  }
 *
 *  // On crée un nouveau tableau de taille size/2
 *  new_array1 <- tableau de taille size/2
 *  // On crée un nouveau tableau de taille size/2
 *  new_array2 <- tableau de taille size/2
 *
 *  // On copie les éléments du tableau dans le premier nouveau tableau
 *  pour i allant de 1 à size/2 {
 *  new_array1[i] <- array[i]
 *  }
 *  // On copie les éléments du tableau dans le second nouveau tableau
 *  pour i allant de size/2 + 1 à size {
 *  new_array2[i - size/2] <- array[i]
 *  }
 *
 *  // On trie le premier nouveau tableau
 *  new_array1 <- merge_sort(new_array1, size/2)
 *  // On trie le second nouveau tableau
 *  new_array2 <- merge_sort(new_array2, size/2)
 *
 *  // On fusionne les deux tableaux
 *  return merge_array(new_array1, size/2, new_array2, size/2)
 *  }
 *  Compléxité :
 *  -> O(n log(n)) dans le pire cas
 *  -> O(n log(n)) dans le meilleur cas
 *  -> O(n log(n)) dans le cas moyen
 *  Explications :
 *  On divise le tableau en deux à chaque fois, donc log(n)
 *  On doit faire n comparaisons pour chaque élément, donc O(n)
 *  Donc O(n log(n))
 *
 *  Bonus :
 *  Merge Sort est un algorithme de type "Diviser pour régner".
 *  Il utilise la récursivité pour diviser le tableau en deux à chaque fois.
 *  Il utilise ensuite la fonction merge_array pour fusionner les deux tableaux.
 *  Il est donc plus efficace que le tri par insertion et le tri par sélection.
 *  Il est possible d'implémenter le tri fusion en utilisant du parallelisme afin d'accélérer le tri.
 *  On peut combiner le tri fusion avec le tri par insertion pour améliorer les performances.
 *  Il suffit de trier les petits tableaux avec le tri par insertion et de fusionner les tableaux avec le tri fusion.
 *  On peut également utiliser le tri fusion pour trier des listes chaînées.
 */

// ----------------------------------- Ex 3.4 -----------------------------------
/*
 * Ex 3.4
 * Trier une matrice:
 * Méthode:
 * 1. On crée un nouveau tableau de taille n * m
 * 2. On copie les éléments de la matrice dans le tableau (ligne par ligne) : O(n * m)
 * 3. On trie le tableau : O(n * m log(n * m)) (tri fusion)
 * 4. On copie les éléments du tableau dans la matrice (ligne par ligne) : O(n * m)
 * 5. On retourne la matrice
 * 6. Magie !
 *
 * Compléxité :
 * ->  O(n * m log(n * m)) dans le pire cas  (tri fusion)
 * ->  O(n * m log(n * m)) dans le meilleur cas (tri fusion)
 * ->  O(n * m log(n * m)) dans le cas moyen  (tri fusion)
 * Explications :
 * On doit copier les éléments de la matrice dans le tableau, donc O(n * m)
 * On doit trier le tableau, donc O(n * m log(n * m))
 * On doit copier les éléments du tableau dans la matrice, donc O(n * m)
 * Donc O(n * m log(n * m)) parcequ'on supprime les valeurs négligeables (n * m)
 *
 * Pseudo code :
 * fn sort_matrix(matrix, n, m) {
 * // On crée un nouveau tableau de taille n * m
 *  new_array <- tableau de taille n * m
 *  index <- 1 // On initialise l'index du tableau
 *  // On copie les éléments de la matrice dans le tableau (ligne par ligne)
 *  pour i allant de 1 à n {
 *      pour j allant de 1 à m {
 *          new_array[index] <- matrix[i][j]
 *          index <- index + 1
 *      }
 *  }
 *  // On trie le tableau
 *  new_array <- merge_sort(new_array, n * m)
 *  index <- 1 // On réinitialise l'index du tableau
 *  // On copie les éléments du tableau dans la matrice (ligne par ligne)
 *  pour i allant de 1 à n {
 *    pour j allant de 1 à m {
 *      matrix[i][j] <- new_array[index]
 *      index <- index + 1
 *      }
 *  }
 * }
 */

// ----------------------------------- Ex 3.5 -----------------------------------
/*
 * Ex 3.5
 * Min Heap
 * Min Heap est un arbre binaire dans lequel chaque noeud est inférieur ou égal à ses deux enfants.
 * La racine est le plus petit élément de l'arbre.
 * Dessin d'un Min Heap à partir d'un tableau [1, 5, 10, 6, 9, 12, 14, 11]:
 *        1
 *      5   10
 *     6 9 12 14
 *   11
 *
 * On insère 4 dans le Min Heap: [1, 5, 10, 6, 9, 12, 14, 11, 4]
 * Dessin du Min Heap après insertion:
 *       1
 *     4   10
 *    5 9 12 14
 *  6 11
 *
 * On change la racine (1) par 7: [7, 5, 10, 6, 9, 12, 14, 11, 4]
 * Dessin du Min Heap après changement:
 *        4
 *      5   10
 *     6 9 12 14
 *   7 11
 *
 *   Algorithme de construction d'un Min Heap:
 *   1. On crée un tableau vide
 *   2. On ajoute les éléments un par un dans le tableau
 *   3. On appelle la fonction heapify pour chaque élément ajouté
 *   4. On retourne le tableau
 *
 *   Algorithme de heapify:
 *   1. On vérifie si l'élément est plus petit que ses enfants
 *   2. Si oui, on ne fait rien
 *   3. Si non, on échange l'élément avec son enfant le plus petit
 *   4. On appelle la fonction heapify sur l'enfant échangé
 *
 *   Algorithme de Heap Sort:
 *   1. On crée un Min Heap à partir du tableau
 *   2. On échange la racine avec le dernier élément du tableau
 *   3. On appelle la fonction heapify sur la racine
 *   4. On répète les étapes 2 et 3 jusqu'à ce que le tableau soit trié
 *
 *   Compléxité:
 *   ->  O(n log(n)) dans le pire cas
 *   ->  O(n log(n)) dans le meilleur cas
 *   ->  O(n log(n)) dans le cas moyen
 *   Explications:
 *   On doit créer le Min Heap, donc O(n)
 *   On doit appeler la fonction heapify sur chaque élément, donc O(n log(n))
 *   Donc O(n log(n)) parcequ'on supprime les valeurs négligeables (n)
 *
 *   Exemple de Heap Sort avec le tableau [1, 5, 10, 6, 9, 12, 14, 11]:
 *   Création du Min Heap:
 *   [1, 5, 10, 6, 9, 12, 14, 11]
 *   Formules pour les enfants et le parent:
 *   enfant gauche = 2 * i
 *   enfant droit = 2 * i + 1
 *   parent = i / 2
 *
 *   Dessin du Min Heap après premier échange:
 *        11
 *      5   10
 *     6 9 12 14
 *   1
 *
 *  Dessin du Min Heap après heapify:
 *     5
 *   6   10
 * 11 9 12 14
 *
 * [1]
 *
 *  On cache le 1 et on répète les étapes 2 et 3:
 *  Dessin du Min Heap après deuxième échange:
 *    14
 *   6 10
 * 11 9 12 5
 * Dessin du Min Heap après heapify:
 *     6
 *    9 10
 *  11 14 12
 *
 *  [5, 1]
 *
 *  Dessin du Min Heap après troisième échange:
 *     12
 *   9   10
 * 11 14 6
 *
 * [6,5,1]
 *
 * Dessin du Min Heap après heapify:
 *     9
 *   11 10
 * 12 14
 *
 *    14
 *   11 10
 *  12 9
 *
 *  [9,6,5,1]
 *
 *  ...
 *
 *  [14,11,10,9,6,5,1]
 *
 *  Pseudo code:
 *  fn heapify(array, i, n) {
 *    // On définit les enfants et le plus petit élément
 *    left <- 2 * i
 *    right <- 2 * i + 1
 *    smallest <- i
 *    // On vérifie si l'enfant gauche est plus petit que l'élément
 *    si left <= n et array[left] < array[i] {
 *      smallest <- left
 *      }
 *    // On vérifie si l'enfant droit est plus petit que l'élément
 *    si right <= n et array[right] < array[smallest] {
 *     smallest <- right
 *     }
 *     // Si l'élément n'est pas le plus petit, on échange
 *     si smallest != i {
 *      swap(array[i], array[smallest])
 *      // On appelle la fonction heapify sur l'enfant échangé
 *      heapify(array, smallest, n)
 *     }
 * }
 *
 * fn heap_sort(array, n) {
 *  // On crée le Min Heap
 *  pour i allant de n/2 à 1 {
 *      heapify(array, i, n)
 *   }
 *
 *  pour i allant de n à 1 {
 *    // On échange la racine avec le dernier élément
 *    swap(array[1], array[i])
 *    // On appelle la fonction heapify sur la racine
 *    heapify(array, 1, i - 1) // On enlève 1 à i pour ne pas prendre en compte le dernier élément qui est déjà trié
 *  }
 *
 */
