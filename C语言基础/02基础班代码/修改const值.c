void ����ֵ���޸�()
{
    //������ֻ����ȫ����ͨ��ָ���޸�
    const float PI = 3.1415926;
    printf("PI=%f\n", PI);
    float *p = &PI;
    *p = 3.11111111f;
    printf("PI=%f\n", PI);
}