Name_vector = vector

Name_map = vector

Name_stack = vector

COMPILE = c++ -Wall -Werror -Wextra

Flag = -std=c++98

SR_F = 	main_vector.cpp.cpp\
		#conversions.cpp\
		#main.cpp

vector: $(Name_vector)
$(Name_vector) : $(SR_F)
	@$(COMPILE) $(Flag) $(SR_F) -o $(NAME)
	@echo "\033[0;32mvector generated"

clean:
	@echo "\033[0;31mFiles deleted"

fclean : clean
	@rm -rf $(Name_vector)

re : fclean all

.PHONNY: all clean fclean re