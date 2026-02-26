
#define MACRO_SYZ_ADDQDISC_ROOT(type, name)                                 \
static long syz_addqdisc_root_##name(volatile long opts, volatile long size)\
{                                                                           \
        return pseudo_addqdisc(type, ROOT_ID, opts, size);                        \
}                                                                           \

#define MACRO_SYZ_ADDQDISC(type, name)                                                       \
static long syz_addqdisc_##name(volatile long parent, volatile long opts, volatile long size)\
{                                                                                            \
        return pseudo_addqdisc(type, parent, opts, size);                                          \
}                                                                                            \


#define MACRO_SYZ_ADDCLASS(type, name)                                                                                \
static long syz_addclass_##name(volatile long portid, volatile long class_num, volatile long opts, volatile long size)\
{                                                                                                                     \
        return pseudo_addclass(type, portid, class_num, opts, size);                                                                    \
}                                                                                                                      \



#define MACRO_SYZ_CHANGEQDISC(type, name)                                                       \
static long syz_changeqdisc_##name(volatile long handle, volatile long opts, volatile long size)\
{                                                                                               \
        return pseudo_changeqdisc(type, handle, opts, size);                                          \
}                                                                                               \
                                    
                                                                              


enum qdisc_type {
    Q_UNDEF,
    Q_CAKE,
    Q_CBS,
    Q_CHOKE,
    Q_CODEL,
    Q_ETF,
    Q_ETS,
    Q_BFIFO,
    Q_PFIFO,
    Q_PFIFO_HEAD_DROP,
    Q_FQ,
    Q_FQ_CODEL,
    Q_FQ_PIPE,
    Q_GRED,
    Q_HHF,
    Q_NETEM,
    Q_PIE,
    Q_PRIO,
    Q_PLUG,
    Q_RED,
    Q_SFB,
    Q_SFQ,
    Q_SKBPRIO,
    Q_TBF,
    Q_DUALAPI,
    Q_DRR,
    Q_BLACKHOLE,
    Q_PFIFO_FAST,
    Q_QFQ,
    Q_HTB,
    Q_HFSC,
    Q_MAX,
    Q_ERROR
};

typedef void (*qdisc_faill_func)(char* error, int error_num);

extern "C" void __setup_qdisc(const char* arg_ifname, const qdisc_faill_func func);
extern "C" void __reset_qdisc();

extern "C" long pseudo_addqdisc(volatile long arg_type, volatile long arg_handle_parent, volatile long arg_opt, volatile long arg_opt_size);
extern "C" long pseudo_changeqdisc(volatile long arg_type, volatile long arg_handle, volatile long arg_opt, volatile long arg_opt_size);
extern "C" long pseudo_delqdisc(volatile long arg_handle);

extern "C" long pseudo_addclass(volatile long arg_type, volatile long arg_handle_port, volatile long arg_class_num, volatile long arg_opt, volatile long arg_opt_size);
extern "C" long pseudo_changeclass(volatile long arg_type, volatile long arg_handle, volatile long arg_opt, volatile long arg_opt_size);
extern "C" long pseudo_delclass(volatile long arg_handle);

extern "C" long pseudo_sendprio(volatile long arg_handle, volatile long count, volatile long size);

const long ROOT_ID = 0xbeef000000ffff00;

static void reset_qdisc()
{
    __reset_qdisc();
}

extern "C" void error(char* error, int error_num)
{
    failmsg("error -> ", "%s , %d", error, error_num);
}

static void setup_qdisc()
{
    __setup_qdisc("lo", &error);
}

MACRO_SYZ_ADDQDISC_ROOT(Q_DRR,   drr)
MACRO_SYZ_ADDQDISC_ROOT(Q_ETS,   ets)
MACRO_SYZ_ADDQDISC_ROOT(Q_HFSC,  hfsc)
MACRO_SYZ_ADDQDISC_ROOT(Q_HTB,   htb)
MACRO_SYZ_ADDQDISC_ROOT(Q_PRIO,  prio)
MACRO_SYZ_ADDQDISC_ROOT(Q_QFQ,   qfq)

MACRO_SYZ_ADDQDISC(Q_CAKE,  cake)
MACRO_SYZ_ADDQDISC(Q_CBS,   cbs)
MACRO_SYZ_ADDQDISC(Q_NETEM, netem)
MACRO_SYZ_ADDQDISC(Q_RED,   red)
MACRO_SYZ_ADDQDISC(Q_SFB,   sfb)
MACRO_SYZ_ADDQDISC(Q_TBF,   tbf)
MACRO_SYZ_ADDQDISC(Q_DRR,   drr)
MACRO_SYZ_ADDQDISC(Q_ETS,   ets)
MACRO_SYZ_ADDQDISC(Q_HFSC,  hfsc)
MACRO_SYZ_ADDQDISC(Q_HTB,   htb)
MACRO_SYZ_ADDQDISC(Q_PRIO,  prio)
MACRO_SYZ_ADDQDISC(Q_QFQ,   qfq)

MACRO_SYZ_ADDCLASS(Q_DRR, drr)
MACRO_SYZ_ADDCLASS(Q_ETS, ets)
MACRO_SYZ_ADDCLASS(Q_HFSC, hfsc)
MACRO_SYZ_ADDCLASS(Q_HTB, htb)
MACRO_SYZ_ADDCLASS(Q_PRIO, prio)
MACRO_SYZ_ADDCLASS(Q_QFQ, qfq)

MACRO_SYZ_CHANGEQDISC(Q_CAKE, cake)
MACRO_SYZ_CHANGEQDISC(Q_CBS, cbs)
MACRO_SYZ_CHANGEQDISC(Q_NETEM, netem)
MACRO_SYZ_CHANGEQDISC(Q_RED, red)
MACRO_SYZ_CHANGEQDISC(Q_SFB, sfb)
MACRO_SYZ_CHANGEQDISC(Q_TBF, tbf)
MACRO_SYZ_CHANGEQDISC(Q_ETS, ets)
MACRO_SYZ_CHANGEQDISC(Q_PRIO, prio)


static long syz_delqdisc(volatile long handle)
{                                                       
        return pseudo_delqdisc(handle);                  
}               

static long syz_delclass(volatile long handle)
{                                                       
        return pseudo_delclass(handle);                 
}    

static long syz_sendprio(volatile long handle, volatile long count, volatile long size)
{                                                                                             
        return pseudo_sendprio(handle, count, size);                                          
}                                                                                             

