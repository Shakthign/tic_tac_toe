#include <gtk/gtk.h>
#include<stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
void quit_window(GtkWidget * window, gpointer data);
void output(GtkWidget *parent, gchar symbol);
void print(GtkWidget *button, gint data);
void start(void);
void win_sound(void);
void draw_sound(void);
void button_click(void);
int check(char symbol);
char array[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int player;
static const char *startgame = "/home/user/Downloads/game-start-6104.mp3";
static const char *winningsound = "/home/user/Downloads/mixkit-animated-small-group-applause-523.wav";
static const char *click = "/home/user/Downloads/interface-124464.mp3";
static const char *drawsound = "/home/user/Downloads/videogame-death-sound-43894.mp3";
GtkWidget *window, *button;
void start() 
{
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	Mix_Music *start = Mix_LoadMUS(startgame);
	Mix_PlayMusic(start, 1);
}
void win_sound() 
{
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	Mix_Music *win = Mix_LoadMUS(winningsound);
	Mix_PlayMusic(win, 1);
}
void draw_sound() 
{
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	Mix_Music *draw = Mix_LoadMUS(drawsound);
	Mix_PlayMusic(draw, 1);
}
void button_click() 
{
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	Mix_Music *Click = Mix_LoadMUS(click);
	Mix_PlayMusic(Click, 1);
}
void quit_window(GtkWidget *window, gpointer data)
{
	gtk_main_quit();
}
int main(int argc, char **argv)
{
	gtk_init(&argc, &argv);
	GtkWidget *grid;
	GtkWidget *button;

	start();
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	int index = 0;

	gtk_window_set_title(GTK_WINDOW(window), "TIC-TAC-TOE");
	gtk_container_set_border_width(GTK_CONTAINER(window), 12);
	gtk_widget_set_size_request(window, 100, 50);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	grid = gtk_grid_new();
	gtk_container_add(GTK_WINDOW(window), grid);
	for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
		button = gtk_button_new_with_label(" ");
		g_signal_connect(button, "clicked", G_CALLBACK(print), (void *)index);
		gtk_grid_attach(GTK_GRID(grid), button, i, j, 1, 1);
		index++;
	}
	}
	button = gtk_button_new_with_label("quit");
	g_signal_connect(button, "clicked", G_CALLBACK(quit_window), NULL);
	gtk_grid_attach(GTK_GRID(grid), button, 3, 3, 1, 1);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}
void output(GtkWidget *parent, gchar symbol)
{
	GtkWidget *dialog;

	if (symbol == 'X') {
		dialog = gtk_message_dialog_new(parent, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "PLAYER 1 WIN!!");
		win_sound();
		player--;
	}
		if (symbol == 'O') {
			dialog = gtk_message_dialog_new(parent, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "PLAYER 2 WIN!!");
			win_sound();
			player--;
		}
		if (symbol == 'D') {
			dialog = gtk_message_dialog_new(parent, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "MATCH DRAW!!");
			draw_sound();
		}
		g_signal_connect(dialog, "response", G_CALLBACK(quit_window), dialog);
		gtk_dialog_run(GTK_DIALOG(dialog));
		gtk_widget_destroy(window);
}
void print(GtkWidget *button, gint data)
{
		button_click();
		if (player%2 == 0) {
		gtk_button_set_label(button, "X");
		gtk_widget_set_sensitive(button, FALSE);
		array[data] = 'X';
		check('X');
		player++;
		} else {
		gtk_button_set_label(button, "O");
		gtk_widget_set_sensitive(button, FALSE);
		array[data] = 'O';
		check('O');
		player++;
		}
		if (player == 9)
			output(window, 'D');
}
int check(char symbol)
{
	int n = 0;

	for (n = 0; n < 3; n++) {
		if (array[n] == symbol && array[n+3] == symbol && array[n+6] == symbol)
			output(window, symbol);
	}
		for (n = 0 ; n <= 6; n = n+3) {
			if (array[n] == symbol && array[n+1] == symbol && array[n+2] == symbol)
				output(window, symbol);
		}
		for (n = 0 ; n < 1; n = n+1) {
			if (array[n] == symbol && array[n+4] == symbol && array[n+8] == symbol || array[n+2] == symbol && array[n+4] == symbol && array[n+6] == symbol)
				output(window, symbol);
		}
}
