class Time{
    int hour, minute, second;
    public:
        //Constructors
        Time();
        Time(int h, int m, int s);

        ~Time(){} //Does nothing
        
        //Getters
        int getHour();
        int getMinute();
        int getSecond();

        //Setters
        void setHour(int h);
        void setMinute(int m);
        void setSecond(int s);
};