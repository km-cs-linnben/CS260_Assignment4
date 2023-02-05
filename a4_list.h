class A_list {
    public:
        A_list(int initialSize);    //must be same name as class name
        bool add(int position, int value);
        int remove(int position);
        int peek(int position);
        int *list_itself;
        int endOfList;
};
