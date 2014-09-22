clean:
	find . -perm /u+x -type f | grep -v .*.sample| xargs rm
	find . -name '*.o' -type f| xargs rm
git:
	git add --all .
	echo "input commit message:"
	read $MESSAGE
	git commit -m "$MESSAGE"
	git push origin master
