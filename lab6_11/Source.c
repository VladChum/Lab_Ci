#define _CRT_SECURE_NO_WARNINGS
#define NULL 0
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct Tree
{
	struct Node
	{
		int key;
		struct Node* left;
		struct Node* right;
		int height;
	};
	struct Node* root;
	char* name_tree;
	int size;
};

int check(const char* funcpointer);
void show_menu(int print);
int exist(struct Tree* tree);
void show_all_tree(struct Tree* tree, int count_tree);
int get_item_index(struct Tree* tree, int count_tree, const char* ptr);

void remove_key(struct Tree* tree, int key);
void add(struct Tree* tree, int key);
void clear(struct Tree* tree);
void get_name(struct Tree* tree);
int treecmp(struct Tree* tree1, struct Tree* tree2);
void treecpy(struct Tree* tree1, struct Tree* tree2);
int find_remove(struct Tree* tree, int key);
void left_root_right(struct Tree* tree);
void clear_(struct Node* tree);
int height(struct Node* tree);
void fix_height(struct Node* tree);
int factor(struct Node* tree);
void creation(struct Tree* tree);
void read_left_root_right_(struct Tree* node_tree1, struct Node* node_tree2);
int get_remove(struct Node* node_tree, int i, int key);
int left_root_right_(struct Node* node_tree, int i);

struct Node* balance(struct Node* tree);
struct Node* node(int key);
struct Node* rotate_right(struct Node* p);
struct Node* rotate_left(struct Node* q);
struct Node* find_min(struct Node* tree);
struct Node* remove_min(struct Node* node_tree);
struct Node* remove_(struct Node* node_tree, int key);
struct Node* add_(struct Node* node_tree, int key);

int save_size;

int main()
{
	int count_tree = 0;
	int switch_menu;
	char menu;
	int del_key, add_key;
	struct Tree* tree = 0;
	int change_tree = 0;
	int item_tree1;
	int item_tree2;
	while (1)
	{
		switch_menu = 0;
		show_menu(switch_menu);
		switch_menu = check("");
		if (exist(tree) || switch_menu == 0 || switch_menu == 7)
		{
			switch (switch_menu)
			{
			case 0:
				if (!exist(tree))
				{
					tree = (struct Tree*)calloc(1, sizeof(struct Tree));
					if (tree == NULL)
					{
						printf("\nError to creat now tree");
						return 0;
					}
					change_tree = 0;
					get_name(&tree[0]);
					count_tree++;
				}
				else
				{
					tree = (struct Tree*)realloc(tree, (count_tree + 1) * sizeof(struct Tree));
					if (tree == NULL)
					{
						printf("\nError to creat now tree");
						return 0;
					}
					printf("\nEnter Name of tree: ");
					get_name(&tree[count_tree]);
					change_tree = count_tree;
					count_tree++;
				}
				printf("\nSuccess");
				break;
			case 1:
				show_all_tree(tree, count_tree);
				change_tree = check("\nPlease Enter change tree: ");
				change_tree--;
				if (change_tree > count_tree)
					change_tree = count_tree - 1;
				break;
			case 2:
				add_key = check("\nPlease Enter key: ");
				add(&tree[change_tree], add_key);
				break;
			case 3:
				left_root_right(&tree[change_tree]);
				break;
			case 4:
				left_root_right(&tree[change_tree]);
				int key = check("\nPlease Enter delete number: ");
				remove_key(&tree[change_tree], find_remove(&tree[change_tree], key - 1));
				if (tree[change_tree].root == NULL)
				{
					if (count_tree > 1)
					{
						struct Tree temp = tree[change_tree];
						tree[change_tree] = tree[count_tree - 1];
						tree[count_tree - 1] = temp;
						tree = (struct Tree*)realloc(tree, (count_tree - 1) * sizeof(struct Tree));
					}
					else
					{
						free(tree);
						tree = NULL;
					}
					count_tree--;
				}
				break;
			case 5:
				item_tree1 = get_item_index(tree, count_tree, "\nPlease Enter Tree to compare: ");
				item_tree2 = get_item_index(tree, count_tree, "\nPlease Enter Tree to compare: ");
				if (treecmp(&tree[item_tree1], &tree[item_tree2]) == -1)
				{
					printf("left bigger then right ");
				}
				else
				if (treecmp(&tree[item_tree1], &tree[item_tree2]) == 0)
				{
					printf(" equal!!! ");
				}
				else
				{
					printf("right bigger then left");
				}
				getchar();
				break;
			case 6:
				item_tree1 = get_item_index(tree, count_tree, "\nPlease Enter Tree to copy: ");
				item_tree2 = get_item_index(tree, count_tree, "\nPlease Enter Tree from we get copy: ");
				treecpy(&tree[item_tree1], &tree[item_tree2]);
				break;
			case 7:
				return 0;
			}
		}
		else
		{
			printf("Error. Add tree");
		}
	}
}

void show_menu(int print)
{
	printf("Menu\n");
	printf("0) Make new tree\n");
	printf("1) Change tree\n");
	printf("2) add to tree\n");
	printf("3) show tree\n");
	printf("4) delete from tree\n");
	printf("5) compare tree\n");
	printf("6) copy\n");
	printf("7) close\n");
}

int get_item_index(struct Tree* tree, int count_tree, const char* ptr)
{
	int tree_item;
	show_all_tree(tree, count_tree);
	do
	{
		tree_item = check(ptr);
		tree_item--;
		if (tree_item < count_tree)
			break;
		printf("Error item");
		getchar();
	} while (1);
	return tree_item;
}

void show_all_tree(struct Tree* tree, int count_tree)
{
	for (int i = 0; i < count_tree; i++)
		printf("%d %s \n", i + 1, tree[i].name_tree);
}

int exist(struct Tree* tree)
{
	if (tree == NULL)
		return 0;
	else
		return 1;
}

int check(const char* funcpointer)
{
	int num;
	char temp = '\n';
	do
	{
		printf("%s\n", funcpointer);
		if (scanf("%d%c", &num, &temp) == 2 && temp == '\n' && num < INT_MAX)
			break;

		rewind(stdin);
		printf("\nError: Incorrect input !!! Pleas repeat enter\n");
		getchar();
	} while (1);
	return num;
}

int treecmp(struct Tree* tree1, struct Tree* tree2)
{
	if (tree1->size == tree2->size)
	{
		return check_key(tree1, tree2);
	}
	else if (tree1->size > tree2->size)
		return -1;
	else
		return 1;
}

int check_key(struct Tree* tree1, struct Tree* tree2)
{
	return node_check(tree1->root, tree2->root);
}

int node_check(struct Node* node_tree1, struct Node* node_tree2)
{
	if (node_tree1 != NULL && node_tree2 != NULL)
	{
		node_check(node_tree1->right, node_tree2->right);
		if (!iqual(node_tree1->key, node_tree2->key))
			return iqual(node_tree1->key, node_tree2->key);
		node_check(node_tree1->left, node_tree2->left);
		if (!iqual(node_tree1->key, node_tree2->key))
			return iqual(node_tree1->key, node_tree2->key);
	}
	else if (node_tree1 == NULL && node_tree2 != NULL)
		return -1;
	else if (node_tree1 != NULL && node_tree2 == NULL)
		return 1;
	else
		return 0;
}

int iqual(int temp1, int temp2)
{
	if (temp1 != temp2)
	{
		if (temp1 > temp2)
			return -1;
		else
			return 1;
	}
	return 0;
}

void treecpy(struct Tree* tree1, struct Tree* tree2)
{
	read_left_root_right_(tree1, tree2->root);
}

void read_left_root_right_(struct Tree* tree1, struct Node* node_tree2)
{
	if (node_tree2 != NULL)
	{
		read_left_root_right_(tree1, node_tree2->left);
		add(tree1, node_tree2->key);
		read_left_root_right_(tree1, node_tree2->right);
	}
}

int save_key;

int find_remove(struct Tree* tree, int key)
{
	get_remove(tree->root, 0, key);
	return save_key;
}

int get_remove(struct Node* node_tree, int i, int key)
{
	if (node_tree != NULL && i >= 0)
	{
		i = get_remove(node_tree->left, i, key);
		if (i == key)
		{
			save_key = node_tree->key;
			return -100;
		}
		i++;
		i = get_remove(node_tree->right, i, key);
		if (i == key)
		{
			save_key = node_tree->key;
			return -100;
		}
	}
	return i;
}


void get_name(struct Tree* tree)
{
	creation(tree);
	printf("Enter Name of tree: ");
	char* temp = (char*)calloc(128, sizeof(char));
	temp = gets(temp);
	tree->name_tree = temp;
}

void left_root_right(struct Tree* tree)
{
	left_root_right_(tree->root, 0);
}

int left_root_right_(struct Node* node_tree, int i)
{
	if (node_tree != NULL)
	{
		i = left_root_right_(node_tree->left, i);
		printf("%d %d \n", i + 1, node_tree->key);
		i++;
		i = left_root_right_(node_tree->right, i);
	}
	return i;
}

struct Node* node(int key)
{
	struct Node* temp = (struct Node*)calloc(1, sizeof(struct Node));
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	temp->height = 1;
	return temp;
}

void add(struct Tree* tree, int key)
{
	save_size = tree->size;
	tree->root = add_(tree->root, key);
	tree->size = save_size;
}

void creation(struct Tree* tree)
{
	tree->root = NULL;
	tree->size = NULL;
}

struct Node* add_(struct Node* node_tree, int key)
{
	if (node_tree == NULL)
	{
		save_size++;
		node_tree = node(key);
		node_tree->key = key;
		return node_tree;
	}
	else
	{
		if (key < node_tree->key)
		{
			node_tree->left = add_(node_tree->left, key);
		}
		else
		{
			node_tree->right = add_(node_tree->right, key);
		}
	}
	return balance(node_tree);
}

int height(struct Node* node_tree)
{
	return (node_tree != NULL) ? node_tree->height : 0;
}


void fixHeight(struct Node* node_tree)
{
	int max;
	max = (height(node_tree->left) < height(node_tree->right) + 1) ? (height(node_tree->right) + 1) : height(node_tree->left);
	node_tree->height = max;
}

struct Node* balance(struct Node* node_tree)
{
	fixHeight(node_tree);
	if (factor(node_tree) >= 2) {
		if (factor(node_tree->right) < 0)
			node_tree->right = rotate_right(node_tree->right);
		return rotate_left(node_tree);
	}
	if (factor(node_tree) <= -2) {
		if (factor(node_tree->left) > 0)
			node_tree->left = rotate_left(node_tree->left);
		return rotate_right(node_tree);
	}
	return node_tree;
}

int factor(struct Node* node_tree) {
	return height(node_tree->right) - height(node_tree->left);
}

struct Node* rotate_right(struct Node* node_tree) {
	struct Node* temp = node_tree->left;
	node_tree->left = temp->right;
	temp->right = node_tree;
	fixHeight(node_tree);
	fixHeight(temp);
	return temp;
}

struct Node* rotate_left(struct Node* node_tree) {
	struct Node* temp = node_tree->right;
	node_tree->right = temp->left;
	temp->left = node_tree;
	fixHeight(node_tree);
	fixHeight(temp);
	return temp;
}

struct Node* find_min(struct Node* node_tree)
{
	return node_tree->left ? find_min(node_tree->left) : node_tree;
}

void clear(struct Tree* tree)
{
	clear_(tree->root);
	tree->root = NULL;
}

void clear_(struct Node* node_tree)
{
	if (node_tree != NULL)
	{
		clear_(node_tree->left);
		clear_(node_tree->right);
		save_size--;
		free(node_tree);

	}
}

struct Node* remove_min(struct Node* node_tree)
{
	if (node_tree->left == NULL)
		return node_tree->right;
	node_tree->left = remove_min(node_tree->left);
	return balance(node_tree);
}

void remove_key(struct Tree* tree, int key)
{
	save_size = tree->size;
	tree->root = remove_(tree->root, key);
	tree->size = save_size;
	if (tree->size == 0)
		tree->root = NULL;
}

struct Node* remove_(struct Node* node_tree, int key)
{
	if (!node_tree) return 0;
	if (key < node_tree->key)
		node_tree->left = remove_(node_tree->left, key);
	else if (key > node_tree->key)
		node_tree->right = remove_(node_tree->right, key);
	else
	{
		save_size--;
		struct Node* left = node_tree->left;
		struct Node* right = node_tree->right;
		if (!right) return left;
		struct Node* min = find_min(right);
		free(node_tree);
		min->right = remove_min(right);
		min->left = left;
		return balance(min);
	}
	return balance(node_tree);
}