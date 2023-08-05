/* appearance */
static const int sloppyfocus        = 1;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
static const unsigned int borderpx  = 1;  /* border pixel of windows */
static const int lockfullscreen     = 1;  /* 1 will force focus on the fullscreen window */
static const float rootcolor[]      = {0.3, 0.3, 0.3, 1.0};
static const float bordercolor[]    = {0.1, 0.5, 0.5, 1.0};
static const float focuscolor[]     = {0.7, 0.1, 0.9, 1.0};
static const float fullscreen_bg[]         = {0.1, 0.1, 0.1, 1.0};

/* tagging */
static const int tagcount = 9;

static const char *tags[] = { "a", "r", "s", "t", "d", "g", "p", "b", "v" };

static const Rule rules[] = {
	/* app_id     title       tags mask     isfloating   monitor */
	/* examples:
	{ "Gimp",     NULL,       0,            1,           -1 },
	*/
        { "Gimp",     NULL,       0,            1,           -1 },
	// { "firefox",  NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
        { "[M]",      monocle },
	{ "><>",      NULL },    /* no layout function means floating behavior */

};

/* monitors */
static const MonitorRule monrules[] = {
	/* name       mfact nmaster scale layout       rotate/reflect */
	/* example of a HiDPI laptop monitor:
	{ "eDP-1",    0.5,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL },
	*/
	/* defaults */
        { "HDMI-A-1",       0.5, 1,      2,    &layouts[1], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
	{ "DP-1",           0.5, 1,      1.5,    &layouts[1], WL_OUTPUT_TRANSFORM_90, -4608, 0},
};

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
	/* can specify fields: rules, model, layout, variant, options */
	/* example:
	.options = "ctrl:nocaps",
	*/
	.options = "",
};

static const int repeat_rate = 25;
static const int repeat_delay = 300;

/* Trackpad */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
/* You can choose between:
LIBINPUT_CONFIG_SCROLL_NO_SCROLL
LIBINPUT_CONFIG_SCROLL_2FG
LIBINPUT_CONFIG_SCROLL_EDGE
LIBINPUT_CONFIG_SCROLL_ON_BUTTON_DOWN
*/
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;
/* You can choose between:
LIBINPUT_CONFIG_SEND_EVENTS_ENABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED_ON_EXTERNAL_MOUSE
*/
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;
/* You can choose between:
LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT
LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE
*/
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.0;

/* If you want to use the windows key change this to WLR_MODIFIER_LOGO */
#define MODKEY WLR_MODIFIER_LOGO
#define TAGKEYS(KEY,SKEY,TAG) \
	{ MODKEY,                    KEY,            view,            {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL,  KEY,            toggleview,      {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_SHIFT, SKEY,           tag,             {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL|WLR_MODIFIER_SHIFT,SKEY,toggletag, {.ui = 1 << TAG} }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[] = { "foot-run.sh", NULL };
static const char *menucmd[] = { "wofi-run.sh", NULL };
static const char *browsercmd[] = { "firefox", NULL };
static const char *emacscmd[] = { "emacsclient.sh", NULL };

static const Key keys[] = {
	/* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
	/* modifier                  key                 function        argument */
	{ MODKEY,                    XKB_KEY_apostrophe,          spawn,          {.v = menucmd} },
	{ MODKEY,                    XKB_KEY_Return,     spawn,          {.v = termcmd} },
	{ MODKEY,                    XKB_KEY_slash,      spawn,          {.v = termcmd} },
	{ MODKEY,                    XKB_KEY_w,          spawn,          {.v = browsercmd} },
	{ MODKEY,                    XKB_KEY_f,          spawn,          {.v = emacscmd} },
	{ MODKEY,                    XKB_KEY_n,          focusstack,     {.i = +1} },
	{ MODKEY,                    XKB_KEY_e,          focusstack,     {.i = -1} },
	// { MODKEY,                    XKB_KEY_i,          incnmaster,     {.i = +1} },
	// { MODKEY,                    XKB_KEY_d,          incnmaster,     {.i = -1} },
	{ MODKEY,                    XKB_KEY_h,          setmfact,       {.f = -0.05} },
	{ MODKEY,                    XKB_KEY_l,          setmfact,       {.f = +0.05} },
	// { MODKEY,                    XKB_KEY_Return,     zoom,           {0} },
	//{ MODKEY,                    XKB_KEY_Tab,        view,           {0} },
	{ MODKEY,                    XKB_KEY_q,          killclient,     {0} },
	{ MODKEY,                    XKB_KEY_k,          setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                    XKB_KEY_m,          setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                    XKB_KEY_space,      setlayout,      {0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_space,      togglefloating, {0} },
	{ MODKEY,                    XKB_KEY_j,          togglefullscreen, {0} },
	{ MODKEY,                    XKB_KEY_0,          view,           {.ui = ~0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_parenright, tag,            {.ui = ~0} },
	{ MODKEY,                    XKB_KEY_o,      focusmon,       {.i = WLR_DIRECTION_LEFT} },
	// { MODKEY,                    XKB_KEY_period,     focusmon,       {.i = WLR_DIRECTION_RIGHT} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_less,       tagmon,         {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_greater,    tagmon,         {.i = WLR_DIRECTION_RIGHT} },
	TAGKEYS(          XKB_KEY_a, XKB_KEY_exclam,                     0),
	TAGKEYS(          XKB_KEY_r, XKB_KEY_at,                         1),
	TAGKEYS(          XKB_KEY_s, XKB_KEY_numbersign,                 2),
	TAGKEYS(          XKB_KEY_t, XKB_KEY_dollar,                     3),
	TAGKEYS(          XKB_KEY_d, XKB_KEY_percent,                    4),
	TAGKEYS(          XKB_KEY_g, XKB_KEY_asciicircum,                5),
	TAGKEYS(          XKB_KEY_p, XKB_KEY_ampersand,                  6),
	TAGKEYS(          XKB_KEY_b, XKB_KEY_asterisk,                   7),
	TAGKEYS(          XKB_KEY_v, XKB_KEY_parenleft,                  8),
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Q,          quit,           {0} },

	/* Ctrl-Alt-Backspace and Ctrl-Alt-Fx used to be handled by X server */
	{ WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_Terminate_Server, quit, {0} },
#define CHVT(n) { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};

static const Button buttons[] = {
	{ MODKEY, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ MODKEY, BTN_MIDDLE, togglefloating, {0} },
	{ MODKEY, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
};

static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;

static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;
