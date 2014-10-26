typedef struct {
	int	s_uid;
	int	s_score;
	char	s_name[MAXNAME];
} SCORE;
char	*Scorefile = _PATH_SCORE;
score()
{
	int	inf;
	if ((inf = open(Scorefile, 2)) < 0) {
		perror(Scorefile);
		return;
	}
		read(inf, Top, sizeof Top);
static SCORE	Top[MAXSCORES];
		write(inf, Top, sizeof Top);
	close(inf);
