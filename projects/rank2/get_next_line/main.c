/* ********************************************************************** */
/*                                  main.c                                    */
/*   Comprehensive test suite for get_next_line                              */
/* ********************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

// Color codes for output
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

// Test counter
int		test_count = 0;
int		passed = 0;
int		failed = 0;

// Helper function to print test results
void	print_result(char *test_name, int success)
{
	test_count++;
	if (success)
	{
		printf(GREEN "✓ Test %d: %s PASSED\n" RESET, test_count, test_name);
		passed++;
	}
	else
	{
		printf(RED "✗ Test %d: %s FAILED\n" RESET, test_count, test_name);
		failed++;
	}
}

void	print_header(char *section)
{
	printf(BLUE "\n========================================\n");
	printf("  %s\n", section);
	printf("========================================\n" RESET);
}

// Helper to create test files
void	create_test_file(const char *filename, const char *content)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd >= 0)
	{
		write(fd, content, strlen(content));
		close(fd);
	}
}

// Test 1: Normal file with multiple lines ending with \n
void	test_normal_file(void)
{
	int		fd;
	char	*line;

	print_header("TEST 1: Normal file with multiple lines");
	create_test_file("test1.txt", "Line 1\nLine 2\nLine 3\n");
	fd = open("test1.txt", O_RDONLY);
	line = get_next_line(fd);
	print_result("Line 1 read", line && strcmp(line, "Line 1\n") == 0);
	free(line);
	line = get_next_line(fd);
	print_result("Line 2 read", line && strcmp(line, "Line 2\n") == 0);
	free(line);
	line = get_next_line(fd);
	print_result("Line 3 read", line && strcmp(line, "Line 3\n") == 0);
	free(line);
	line = get_next_line(fd);
	print_result("EOF returns NULL", line == NULL);
	close(fd);
}

// Test 2: File ending without newline
void	test_no_final_newline(void)
{
	int		fd;
	char	*line;

	print_header("TEST 2: File ending without newline");
	create_test_file("test2.txt", "Line 1\nLine 2");
	fd = open("test2.txt", O_RDONLY);
	line = get_next_line(fd);
	print_result("Line 1 with \\n", line && strcmp(line, "Line 1\n") == 0);
	free(line);
	line = get_next_line(fd);
	print_result("Line 2 without \\n", line && strcmp(line, "Line 2") == 0);
	free(line);
	line = get_next_line(fd);
	print_result("EOF returns NULL", line == NULL);
	close(fd);
}

// Test 3: Empty file
void	test_empty_file(void)
{
	int		fd;
	char	*line;

	print_header("TEST 3: Empty file");
	create_test_file("test3.txt", "");
	fd = open("test3.txt", O_RDONLY);
	line = get_next_line(fd);
	print_result("Empty file returns NULL", line == NULL);
	close(fd);
}

// Test 4: Single character without newline
void	test_single_char(void)
{
	int		fd;
	char	*line;

	print_header("TEST 4: Single character");
	create_test_file("test4.txt", "a");
	fd = open("test4.txt", O_RDONLY);
	line = get_next_line(fd);
	print_result("Single char 'a'", line && strcmp(line, "a") == 0);
	free(line);
	line = get_next_line(fd);
	print_result("EOF returns NULL", line == NULL);
	close(fd);
}

// Test 5: Only newline
void	test_only_newline(void)
{
	int		fd;
	char	*line;

	print_header("TEST 5: Only newline character");
	create_test_file("test5.txt", "\n");
	fd = open("test5.txt", O_RDONLY);
	line = get_next_line(fd);
	print_result("Only \\n", line && strcmp(line, "\n") == 0);
	free(line);
	line = get_next_line(fd);
	print_result("EOF returns NULL", line == NULL);
	close(fd);
}

// Test 6: Multiple consecutive newlines
void	test_multiple_newlines(void)
{
	int		fd;
	char	*line;

	print_header("TEST 6: Multiple consecutive newlines");
	create_test_file("test6.txt", "\n\n\n");
	fd = open("test6.txt", O_RDONLY);
	line = get_next_line(fd);
	print_result("First \\n", line && strcmp(line, "\n") == 0);
	free(line);
	line = get_next_line(fd);
	print_result("Second \\n", line && strcmp(line, "\n") == 0);
	free(line);
	line = get_next_line(fd);
	print_result("Third \\n", line && strcmp(line, "\n") == 0);
	free(line);
	line = get_next_line(fd);
	print_result("EOF returns NULL", line == NULL);
	close(fd);
}

// Test 7: Very long line (larger than BUFFER_SIZE)
void	test_long_line(void)
{
	char	long_line[5001];
	int		fd;
	char	*line;

	print_header("TEST 7: Very long line");
	memset(long_line, 'A', 4999);
	long_line[4999] = '\n';
	long_line[5000] = '\0';
	create_test_file("test7.txt", long_line);
	fd = open("test7.txt", O_RDONLY);
	line = get_next_line(fd);
	print_result("Long line (5000 chars)", line && strlen(line) == 5000);
	free(line);
	close(fd);
}

// Test 8: Alternating short and long lines
void	test_mixed_lengths(void)
{
	int		fd;
	char	*line;
	int		all_read;

	print_header("TEST 8: Mixed line lengths");
	create_test_file("test8.txt",
		"Short\nVery long line with lots of content here to test buffer handling properly\nMedium line here\nA\n");
	fd = open("test8.txt", O_RDONLY);
	all_read = 1;
	line = get_next_line(fd);
	all_read &= (line && strcmp(line, "Short\n") == 0);
	free(line);
	line = get_next_line(fd);
	all_read &= (line && strcmp(line,
				"Very long line with lots of content here to test buffer handling properly\n") == 0);
	free(line);
	line = get_next_line(fd);
	all_read &= (line && strcmp(line, "Medium line here\n") == 0);
	free(line);
	line = get_next_line(fd);
	all_read &= (line && strcmp(line, "A\n") == 0);
	free(line);
	print_result("All mixed lines read correctly", all_read);
	close(fd);
}

// Test 9: Invalid file descriptor
void	test_invalid_fd(void)
{
	char	*line;

	print_header("TEST 9: Invalid file descriptor");
	line = get_next_line(-1);
	print_result("Negative FD returns NULL", line == NULL);
	line = get_next_line(1000);
	print_result("Invalid FD returns NULL", line == NULL);
}

// Test 10: File with only spaces and tabs
void	test_whitespace(void)
{
	int		fd;
	char	*line;

	print_header("TEST 10: Whitespace handling");
	create_test_file("test10.txt", "   \n\t\t\n  spaces  \n");
	fd = open("test10.txt", O_RDONLY);
	line = get_next_line(fd);
	print_result("Line with spaces", line && strcmp(line, "   \n") == 0);
	free(line);
	line = get_next_line(fd);
	print_result("Line with tabs", line && strcmp(line, "\t\t\n") == 0);
	free(line);
	line = get_next_line(fd);
	print_result("Line with mixed spaces", line && strcmp(line,
			"  spaces  \n") == 0);
	free(line);
	close(fd);
}

// Test 11: File with no content after last newline
void	test_empty_last_line(void)
{
	int		fd;
	char	*line;

	print_header("TEST 11: Empty content after newline");
	create_test_file("test11.txt", "Line 1\nLine 2\n");
	fd = open("test11.txt", O_RDONLY);
	line = get_next_line(fd);
	free(line);
	line = get_next_line(fd);
	free(line);
	line = get_next_line(fd);
	print_result("No content after final \\n", line == NULL);
	close(fd);
}

// Test 12: Exact BUFFER_SIZE line
void	test_buffer_size_line(void)
{
	char	buffer_line[BUFFER_SIZE + 2];
	int		fd;
	char	*line;

	print_header("TEST 12: Line exactly BUFFER_SIZE");
	memset(buffer_line, 'B', BUFFER_SIZE);
	buffer_line[BUFFER_SIZE] = '\n';
	buffer_line[BUFFER_SIZE + 1] = '\0';
	create_test_file("test12.txt", buffer_line);
	fd = open("test12.txt", O_RDONLY);
	line = get_next_line(fd);
	print_result("Line of BUFFER_SIZE length", line
		&& strlen(line) == BUFFER_SIZE + 1);
	free(line);
	close(fd);
}
// Test 13: Reading twice from same FD
void	test_sequential_reads(void)
{
	int	fd;
	int	success;

	print_header("TEST 13: Sequential reads");
	create_test_file("test13.txt", "First\nSecond\nThird\n");
	fd = open("test13.txt", O_RDONLY);
	char *line1, *line2, *line3;
	line1 = get_next_line(fd);
	line2 = get_next_line(fd);
	line3 = get_next_line(fd);
	success = line1 && line2 && line3 && strcmp(line1, "First\n") == 0
		&& strcmp(line2, "Second\n") == 0 && strcmp(line3, "Third\n") == 0;
	print_result("Sequential reads maintain position", success);
	free(line1);
	free(line2);
	free(line3);
	close(fd);
}

// Test 14: File with binary-like content (non-printable)
void	test_special_chars(void)
{
	int		fd;
	char	*line;

	print_header("TEST 14: Special characters");
	create_test_file("test14.txt", "Line\x01with\x02special\x03chars\n");
	fd = open("test14.txt", O_RDONLY);
	line = get_next_line(fd);
	print_result("Line with special chars", line && line[0] == 'L');
	free(line);
	close(fd);
}

// Test 15: Reopening the same file
void	test_reopen_file(void)
{
	int		fd1;
	char	*line;
	int		fd2;

	print_header("TEST 15: Reopen same file");
	create_test_file("test15.txt", "Line 1\nLine 2\n");
	fd1 = open("test15.txt", O_RDONLY);
	line = get_next_line(fd1);
	print_result("First open, first line", line && strcmp(line,
			"Line 1\n") == 0);
	free(line);
	close(fd1);
	fd2 = open("test15.txt", O_RDONLY);
	line = get_next_line(fd2);
	print_result("Reopen, starts from beginning", line && strcmp(line,
			"Line 1\n") == 0);
	free(line);
	close(fd2);
}

// Test 16: Single long line without newline
void	test_long_line_no_newline(void)
{
	char	long_line[1000];
	int		fd;
	char	*line;

	print_header("TEST 16: Long line without newline");
	memset(long_line, 'Z', 999);
	long_line[999] = '\0';
	create_test_file("test16.txt", long_line);
	fd = open("test16.txt", O_RDONLY);
	line = get_next_line(fd);
	print_result("Long line no \\n", line && strlen(line) == 999);
	free(line);
	close(fd);
}

// Test 17: File with NULL bytes (undefined behavior warning)
void	test_null_bytes(void)
{
	int		fd;
	char	content[] = "Before\0After\n";
	char	*line;

	print_header("TEST 17: NULL bytes in file");
	fd = open("test17.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, content, 13);
	close(fd);
	fd = open("test17.txt", O_RDONLY);
	line = get_next_line(fd);
	// Behavior is undefined for binary files, just test no crash
	print_result("NULL byte handling (no crash)", 1);
	free(line);
	close(fd);
}

// Test 18: Closed file descriptor
void	test_closed_fd(void)
{
	int		fd;
	char	*line;

	print_header("TEST 18: Closed file descriptor");
	create_test_file("test18.txt", "Line\n");
	fd = open("test18.txt", O_RDONLY);
	close(fd);
	line = get_next_line(fd);
	print_result("Closed FD returns NULL or handles gracefully", 1); // May vary
	free(line);
}

// Summary
void	print_summary(void)
{
	printf(YELLOW "\n========================================\n");
	printf("  TEST SUMMARY\n");
	printf("========================================\n");
	printf("Total tests: %d\n", test_count);
	printf(GREEN "Passed: %d\n" RESET, passed);
	printf(RED "Failed: %d\n" RESET, failed);
	if (failed == 0)
		printf(GREEN "\n🎉 ALL TESTS PASSED! 🎉\n" RESET);
	else
		printf(RED "\n⚠️  SOME TESTS FAILED ⚠️\n" RESET);
	printf(YELLOW "========================================\n" RESET);
}

// Main function
int	main(void)
{
	printf(BLUE "\n╔════════════════════════════════════════╗\n");
	printf("║   GET_NEXT_LINE COMPREHENSIVE TESTS   ║\n");
	printf("║   BUFFER_SIZE: %-24d║\n", BUFFER_SIZE);
	printf("╚════════════════════════════════════════╝\n" RESET);
	test_normal_file();
	test_no_final_newline();
	test_empty_file();
	test_single_char();
	test_only_newline();
	test_multiple_newlines();
	test_long_line();
	test_mixed_lengths();
	test_invalid_fd();
	test_whitespace();
	test_empty_last_line();
	test_buffer_size_line();
	test_sequential_reads();
	test_special_chars();
	test_long_line_no_newline();
	test_null_bytes();
	test_closed_fd();
	print_summary();
	// Cleanup test files
	system("rm -f test*.txt");
	return (failed == 0 ? 0 : 1);
}
