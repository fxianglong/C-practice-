#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

//���ͨѶ¼�Ƿ�����  yes->1   no->0
static int IsFull(contact_p ct){
	return ct->size == ct->cap ? 1 : 0;
}
//����ͨѶ¼ yes->1  no->0
static int IncContact(contact_pp ctpp)
{
	int new_size = sizeof(contact_t)+(((*ctpp)->cap) + INC_SIZE)*sizeof(person_t);
	contact_p p = realloc(*ctpp, new_size);
	if (!p){
		printf("Inc Contact Error!\n");
		return 0;
	}
	p->cap = (*ctpp)->cap + INC_SIZE;
	*ctpp = p;
	printf("debug��Inc Contact Success!\n");
	return 1;
}
//�Ƚ�����
static int person_cmp(const void *x, const void *y)
{
	person_p _x = (person_p)x;
	person_p _y = (person_p)y;
	return strcmp(_x->name, _y->name);
}
//����������ͨѶ¼/
static int FindName(contact_p ct, char *name)
{
	int i = 0;
	assert(ct);
	for (i = 0; i < ct->size; i++)
	{
		if (strcmp(ct->list[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//û�ҵ�
}
//�����ṹ������
static void Swap(struct person *a, struct person *b)
{
	struct person tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
void menu()
{
	printf("---------------------------------------\n");
	printf("--  1.��ʾͨѶ¼      2.����       3.ɾ��   --\n");
	printf("--  4.�޸�            5.����       6.����   --\n");
	printf("--  7.���            8.����                --\n");
	printf("---------------------------------------\n");
	printf("Please Enter Your Select:>");
}
int InitContactFile(contact_pp ctpp, FILE *fp)
{
	contact_p p = (contact_p)malloc(sizeof(contact_t));
	if (p){
		fread(p, sizeof(contact_t), 1, fp);
		int _cap = p->cap;
		int size = sizeof(contact_t)+p->cap*sizeof(person_t);
		contact_p p1 = (contact_p)realloc(p, size);
		if (p1){
			p = p1;
			fread(p->list, p->cap*sizeof(person_t), 1, fp);
			*ctpp = p;
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
}

void InitContactDefault(contact_pp ctpp)
{
	*ctpp = malloc(sizeof(contact_t)+sizeof(person_t)*LIST_DEFAULT);
	if (NULL == *ctpp){
		printf("%s: %d\n)", strerror(errno), errno);
		exit(1);//��ֹ����
	}
	(*ctpp)->cap = LIST_DEFAULT;
	(*ctpp)->size = 0;
	printf("debug: ��ʼ���ɹ�!\n");

}
void AddPerson(contact_pp ctpp)
{
	if (!IsFull(*ctpp) || IncContact(ctpp)){
		person_p p = &((*ctpp)->list[(*ctpp)->size]);
		printf("����������: ");
		scanf("%s", &(p->name));
		printf("�������Ա�: ");
		scanf(" %s", &(p->sex));
		printf("����������: ");
		scanf(" %d", &(p->age));
		printf("������绰: ");
		scanf(" %s", &(p->telphone));
		printf("�������ַ: ");
		scanf(" %s", &(p->address));
		(*ctpp)->size++;
	}
	else{
		printf("�ռ�����!\n");
		return;
	}
}
void ShowContact(contact_p ct)
{
	int top = ct->size;
	int i = 0;
	person_p p = ct->list;
	for (; i < top; i++){
		printf("����: %-6s�Ա�: %-3c����: %-3d�绰: %-12sסַ: %-16s\n", \
			p[i].name, p[i].sex, p[i].age, p[i].telphone, p[i].address);
	}
}
void SortContact(contact_p ct)
{
	person_p p = ct->list;
	qsort(p, ct->size, sizeof(person_t), person_cmp);
}
void SearchPerson(contact_p ct)
{
	assert(ct);
	char name[NAME_SIZE] = { 0 };
	int ret = 0;
	printf("��������Ҫ���ҵ�����: ");
	scanf(" %s", name);
	ret = FindName(ct, name);
	if (-1 != ret){
		printf("����: %-6s�Ա�: %-3c����: %-3d�绰: %-12sסַ: %-16s\n", \
			ct->list[ret].name, ct->list[ret].sex, ct->list[ret].age, \
			ct->list[ret].telphone, ct->list[ret].address);
	}
	else{
		printf("��Ǹ��û�и��û�!\n");
	}
}
void ModPerson(contact_pp ctpp)
{
	assert(*ctpp);
	char name[NAME_SIZE] = { 0 };
	int ret = 0;
	printf("��������Ҫ�޸ĵ���ϵ�˵�����: ");
	scanf(" %s", name);
	ret = FindName(*ctpp, name);
	if (-1 != ret){
		person_p p = &((*ctpp)->list[ret]);
		printf("����������: ");
		scanf("%s", p->name);
		printf("�������Ա�: ");
		scanf(" %s", &(p->sex));
		printf("����������: ");
		scanf(" %d", &(p->age));
		printf("������绰: ");
		scanf(" %s", p->telphone);
		printf("�������ַ: ");
		scanf(" %s", p->address);
		printf("�޸ĳɹ�!\n");
	}
	else{
		printf("û�и��û�!\n");
	}
}
void DelPerson(contact_pp ctpp)
{
	assert(*ctpp);
	char name[NAME_SIZE] = { 0 };
	int ret = 0;
	int i = 0;
	printf("��������Ҫɾ���û�������: ");
	scanf(" %s", name);
	ret = FindName(*ctpp, name);
	if (-1 != ret){
		Swap(&(*ctpp)->list[ret], &(*ctpp)->list[(*ctpp)->size - 1]);
		(*ctpp)->size--;
		//for (i = ret; i < (*ctpp)->size; i++){
		//	(*ctpp)->list[i] = (*ctpp)->list[i+1];
		//}
		//(*ctpp)->size--;
		printf("Deleted Success!\n");
	}
	else{
		printf("No Such User!\n");
	}
}
//�˴����ͨѶ¼��û�лָ�ͨѶ¼ԭ���ĳ���
void ClearPerson(contact_pp ctpp)
{
	(*ctpp)->size = 0;
	printf("��ճɹ�!\n");
	return;
}
void Save(contact_p ct)
{
	FILE *fp = fopen(CT_FILE, "wb");
	if (NULL == fp){
		printf("��ʧ��!\n");
		return;
	}
	fwrite(ct, sizeof(contact_t)+sizeof(person_t)*ct->cap, 1, fp);
	fclose(fp);
}
int Load(contact_pp ctpp)
{
	FILE *fp = fopen(CT_FILE, "rb");
	if (NULL == fp){
		printf("��ʼ���ļ�ʧ��!\n");
		InitContactDefault(ctpp);
		return 0;
	}
	int ret = InitContactFile(ctpp, fp);
	fclose(fp);
	return ret;
}