#ifndef F43F89C9_101D_4C45_9ACC_A4785BF60CE7
#define F43F89C9_101D_4C45_9ACC_A4785BF60CE7


namespace ze {


    enum GameObjState {

        Idle = 1 << 0,
        Moving = 1 << 1,
        Left = 1 << 2,
        Right = 1 << 3,
        Top = 1 << 4,
        Down = 1 << 5,
        Attack = 1 << 6,
        Damage = 1 << 7,

        LeftIdle = Idle | Left,
        LeftMoving = Left | Moving,
        LeftAttack = Left | Attack,
        LeftDamage = Left | Damage,

        RightIdle = Idle | Right,
        RightMoving = Moving | Right,
        RightAttack = Attack | Right,
        RightDamage = Damage | Right,

        TopIdle = Idle | Top,
        TopMoving = Moving | Top,
        TopAttack = Attack | Top,
        TopDamage = Damage | Top,

        DownIdle = Idle | Down,
        DownMoving = Moving | Down,
        DownAttack = Attack | Down,
        DownDamage = Damage | Down

    };
    
} // namespace ze


#endif /* F43F89C9_101D_4C45_9ACC_A4785BF60CE7 */
