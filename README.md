# Mav-Shell

A shell program is made using C which tokenizes inputs as commands and executes them as a separate process.
It utilizes functions like fork and exec for forking different processes.

Different features include-
• Tokenization of input
• Forking different processes
• History command(gives a list of last n executed commands)
• Signal handlers for ctrl-C and ctrl-Z.
• Ctrl+C terminates a process and ctrl+z suspends a process.
• bg command(backgrounds a previously suspended process)
• !n command(executes the last nth command from the history of commands)
• listpids command(gives process ids of last 15 processes executed by the shell)
