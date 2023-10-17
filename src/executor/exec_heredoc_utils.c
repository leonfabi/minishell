int	*get_close_fd(void)
{
	static int	fd;

	return (&fd);
}

void	set_close_fd(int set_fd)
{
	int		*fd;

	fd = get_close_fd();
	*fd = set_fd;
}
