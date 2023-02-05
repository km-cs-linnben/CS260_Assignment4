class a_list {
    public:
        a_list(int initialSize);
        bool add(int position, int value);
        bool remove(int position);
        int peek(int position);
        int *list_itself;
        int endOfList;
};
