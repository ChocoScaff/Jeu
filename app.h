
App App_Init(void);
void App_Background(App *app,unsigned char R,unsigned char G,unsigned char B,unsigned char O);
void App_RenderPresent(App *app);
void App_Destroy(App *app);
void App_Fullscreen(App *app);
#ifdef DEBUG_SHOW_SYSTEM
void App_ShowSystem(void);
#endif // DEBUG_SHOW_SYSTEM
