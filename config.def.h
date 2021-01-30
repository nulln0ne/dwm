/* See LICENSE file for copyright and license details. */

static const unsigned int borderpx  = 2;
static const unsigned int snap      = 32;
static const int swallowfloating    = 0;
static const unsigned int systraypinning = 0;
static const unsigned int systrayspacing = 2;
static const int systraypinningfailfirst = 1;
static const int showsystray        = 1;
static const int showbar            = 1;
static const int topbar             = 1;
static const char *fonts[]          = { "terminus:size=11" };
static const char *colors[][3]      = {
	[SchemeNorm] = { "#839496", "#002b36", "#002b36" },
	[SchemeSel]  = { "#839496", "#073642", "#00323e" },
};

static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "URxvt",   NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

static const float mfact     = 0.5;
static const int nmaster     = 1;
static const int resizehints = 0;

static const Layout layouts[] = {
	{ "[]=",      tile },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/zsh", "-c", cmd, NULL } }

#include <X11/XF86keysym.h>
static Key keys[] = {
	{ MODKEY,                       XK_d,                    spawn,          SHCMD("dmenu_run") },
	{ MODKEY,                       XK_Return,               spawn,          SHCMD("urxvt") },
	{ MODKEY,                       XK_w,                    spawn,          SHCMD("chromium") },
	{ MODKEY,                       XK_f,                    spawn,          SHCMD("urxvt -e lf") },
    { Mod1Mask|ControlMask,         XK_3,                    spawn,          SHCMD("maim -u | xclip -selection clipboard -t image/png") },
    { Mod1Mask|ControlMask,         XK_4,                    spawn,          SHCMD("maim -su | xclip -selection clipboard -t image/png") },
    { 0,                            XF86XK_AudioLowerVolume, spawn,          SHCMD("amixer set Master -q 10%-") },
	{ 0,                            XF86XK_AudioMute,        spawn,          SHCMD("amixer set Master -q toggle") },
	{ 0,                            XF86XK_AudioRaiseVolume, spawn,          SHCMD("amixer set Master -q 10%+") },
    { 0,                            XF86XK_MonBrightnessUp,  spawn,          SHCMD("brightnessctl s 10%+") },
    { 0,                            XF86XK_MonBrightnessDown,spawn,          SHCMD("brightnessctl s 10%-") },
    { MODKEY|ShiftMask,             XK_f,                    togglefullscr,  {0} },
	{ MODKEY,                       XK_comma,                incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_period,               incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,                    setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,                    setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_s,                    zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_q,                    killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_space,                togglefloating, {0} },
	TAGKEYS(                        XK_1,                    0)
	TAGKEYS(                        XK_2,                    1)
	TAGKEYS(                        XK_3,                    2)
	TAGKEYS(                        XK_4,                    3)
	TAGKEYS(                        XK_5,                    4)
	TAGKEYS(                        XK_6,                    5)
	TAGKEYS(                        XK_7,                    6)
	TAGKEYS(                        XK_8,                    7)
	TAGKEYS(                        XK_9,                    8)
	{ MODKEY|ShiftMask,             XK_e,                    quit,         {0} },
};

static Button buttons[] = {
	{ ClkClientWin,                 MODKEY,                  Button1,      movemouse,         {0} },
};
