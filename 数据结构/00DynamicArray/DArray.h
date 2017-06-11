#ifndef _DARRAY_H
#define _DARRAY_H

// �Զ���һ���ṹ�� - ��̬����
// ������̬����
typedef struct darray
{
    // ����
    int capacity;
    // ����-�Ѿ��洢��Ԫ�ظ���
    int size;
    // �洢���ݵ�����
    // �洢�������������
    // void* data[];
    void** data;
}DArray;

// ����C++��������C�ķ�ʽ�������º���
#ifdef __cplusplus
extern "C" {
#endif

    // ��������
    // ��ʼ����̬����
    DArray* Init_DArray(int capacity);
    // Ԫ�صĲ���
    void Insert_DArray(DArray* arry, int pos, void* data);
    // Ԫ�ص�ɾ��
    void Delete_DArray(DArray*arry, int pos);
    // ���� - ��ӡ�����ֵ
    // ��֪�����ݵ�ʵ������ - �ṩһ���ص�����
    // �û�֪��, ���û��ṩ��������, �ڵ�ǰ�ӿ��е����û��ṩ�Ľӿں���
    // ����ָ������ - ʵ�ֻص�����
    // ����ָ����Ǻ����ĵ�ַ - ������
    // �ص��������ص�:
    // --	��Ҫ�û��Լ�д, ����Ҫ�õ���(��Ҫ�ṩһ������ָ��)
    // --   ʵ�ֵ���ͨ����: �ֽ�д, �Լ�����
    void Traverse_DArray(DArray* arry, void(*print)(void*));
    // �ͷŶ�̬����
    void Destroy_DArray(DArray* arry);

#ifdef __cplusplus
}
#endif

#endif