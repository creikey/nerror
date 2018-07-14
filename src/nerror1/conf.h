// Configures the messages
#ifndef H_CONF
#define H_CONF

#ifdef __cplusplus
extern "C" {
#endif

// -------------------conf---------------------
#define INCLUDE_TIME
#define INCLUDE_DATE
#define INCLUDE_COLORS
#define INCLUDE_POSITION
#define INCLUDE_FUNCTION

#define LOW_THRESH_MESSAGE "   Notice   -- "
#define MED_THRESH_MESSAGE " ⚡Warning  -- "
#define HIH_THRESH_MESSAGE " ⚠️ ERROR    -- "
#define LOW_THRESH_COLOR "\033[0m"
#define MED_THRESH_COLOR "\033[33m"
#define HIH_THRESH_COLOR "\033[31m"
// -------------------ends---------------------

#ifndef INCLUDE_COLORS
#define LOW_THRESH_COLOR "\033[0m"
#define MED_THRESH_COLOR "\033[0m"
#define HIH_THRESH_COLOR "\033[0m"
#endif // ifndef INCLUDE_COLORS

#ifdef __cplusplus
}
#endif

#endif // H_CONF
