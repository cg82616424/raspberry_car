class speed
{
public:
    static int left_gipo_index;
    static int right_gpio_index;
    int left_speed;
    int right_speed;
    static int speed_count[60];
    static void update_speed();
    void (*p_get_speed)();
    speed(int,int);
    static void get_speed();
    virtual ~speed();
};
