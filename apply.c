		     const char *prefix,
		     struct lock_file *lock_file)
	state->prefix_length = state->prefix ? strlen(state->prefix) : 0;
	state->lock_file = lock_file;
	state->newfd = -1;
	if (!state->lock_file)
		return error("BUG: state->lock_file should not be NULL");
/*
 * This represents a "patch" to a file, both metainfo changes
 * such as creation/deletion, filemode and content changes represented
 * as a series of fragments.
 */
struct patch {
	char *new_name, *old_name, *def_name;
	unsigned int old_mode, new_mode;
	int is_new, is_delete;	/* -1 = unknown, 0 = false, 1 = true */
	int rejected;
	unsigned ws_rule;
	int lines_added, lines_deleted;
	int score;
	unsigned int is_toplevel_relative:1;
	unsigned int inaccurate_eof:1;
	unsigned int is_binary:1;
	unsigned int is_copy:1;
	unsigned int is_rename:1;
	unsigned int recount:1;
	unsigned int conflicted_threeway:1;
	unsigned int direct_to_threeway:1;
	struct fragment *fragments;
	char *result;
	size_t resultsize;
	char old_sha1_prefix[41];
	char new_sha1_prefix[41];
	struct patch *next;

	/* three-way fallback result */
	struct object_id threeway_stage[3];
};

	const char *last1 = s1 + n1 - 1;
	const char *last2 = s2 + n2 - 1;
	int result = 0;
	while ((*last1 == '\r') || (*last1 == '\n'))
		last1--;
	while ((*last2 == '\r') || (*last2 == '\n'))
		last2--;

	/* skip leading whitespaces, if both begin with whitespace */
	if (s1 <= last1 && s2 <= last2 && isspace(*s1) && isspace(*s2)) {
		while (isspace(*s1) && (s1 <= last1))
			s1++;
		while (isspace(*s2) && (s2 <= last2))
			s2++;
	}
	/* early return if both lines are empty */
	if ((s1 > last1) && (s2 > last2))
		return 1;
	while (!result) {
		result = *s1++ - *s2++;
		/*
		 * Skip whitespace inside. We check for whitespace on
		 * both buffers because we don't want "a b" to match
		 * "ab"
		 */
		if (isspace(*s1) && isspace(*s2)) {
			while (isspace(*s1) && s1 <= last1)
			while (isspace(*s2) && s2 <= last2)
		}
		/*
		 * If we reached the end on one side only,
		 * lines don't match
		 */
		if (
		    ((s2 > last2) && (s1 <= last1)) ||
		    ((s1 > last1) && (s2 <= last2)))
		if ((s1 > last1) && (s2 > last2))
			break;
	return !result;
static char *find_name_gnu(struct apply_state *state,
			   const char *def,
	 * http://marc.info/?l=git&m=112927316408690&w=2
	if (state->root.len)
		strbuf_insert(&name, 0, state->root.buf, state->root.len);
static char *find_name_common(struct apply_state *state,
	if (state->root.len) {
		char *ret = xstrfmt("%s%.*s", state->root.buf, len, start);
static char *find_name(struct apply_state *state,
		char *name = find_name_gnu(state, line, def, p_value);
	return find_name_common(state, line, def, p_value, NULL, terminate);
static char *find_name_traditional(struct apply_state *state,
		char *name = find_name_gnu(state, line, def, p_value);
		return find_name_common(state, line, def, p_value, NULL, TERM_TAB);
	return find_name_common(state, line, def, p_value, line + len, 0);
}

static int count_slashes(const char *cp)
{
	int cnt = 0;
	char ch;

	while ((ch = *cp++))
		if (ch == '/')
			cnt++;
	return cnt;
	name = find_name_traditional(state, nameline, NULL, 0);
		if (!strncmp(name, state->prefix, state->prefix_length))
			if (!strncmp(cp, state->prefix, state->prefix_length))
		"^(1969-12-31|1970-01-01)"
		" "
		"[0-2][0-9]:[0-5][0-9]:00(\\.0+)?"
	int zoneoffset;
	int hourminute;
	/*
	 * YYYY-MM-DD hh:mm:ss must be from either 1969-12-31
	 * (west of GMT) or 1970-01-01 (east of GMT)
	 */
	if ((zoneoffset < 0 && memcmp(timestamp, "1969-12-31", 10)) ||
	    (0 <= zoneoffset && memcmp(timestamp, "1970-01-01", 10)))
		return 0;

	hourminute = (strtol(timestamp + 11, NULL, 10) * 60 +
		      strtol(timestamp + 14, NULL, 10) -
		      zoneoffset);

	return ((zoneoffset < 0 && hourminute == 1440) ||
		(0 <= zoneoffset && !hourminute));
		name = find_name_traditional(state, second, NULL, state->p_value);
		name = find_name_traditional(state, first, NULL, state->p_value);
		first_name = find_name_traditional(state, first, NULL, state->p_value);
		name = find_name_traditional(state, second, first_name, state->p_value);
static int gitdiff_hdrend(struct apply_state *state,
static int gitdiff_verify_name(struct apply_state *state,
		*name = find_name(state, line, NULL, state->p_value, TERM_TAB);
		int len = strlen(*name);
		another = find_name(state, line, NULL, state->p_value, TERM_TAB);
		if (!another || memcmp(another, *name, len + 1)) {
		/* expect "/dev/null" */
		if (memcmp("/dev/null", line, 9) || line[9] != '\n')
static int gitdiff_oldname(struct apply_state *state,
static int gitdiff_newname(struct apply_state *state,
static int gitdiff_oldmode(struct apply_state *state,
	patch->old_mode = strtoul(line, NULL, 8);
	return 0;
static int gitdiff_newmode(struct apply_state *state,
	patch->new_mode = strtoul(line, NULL, 8);
	return 0;
static int gitdiff_delete(struct apply_state *state,
static int gitdiff_newfile(struct apply_state *state,
static int gitdiff_copysrc(struct apply_state *state,
	patch->old_name = find_name(state, line, NULL, state->p_value ? state->p_value - 1 : 0, 0);
static int gitdiff_copydst(struct apply_state *state,
	patch->new_name = find_name(state, line, NULL, state->p_value ? state->p_value - 1 : 0, 0);
static int gitdiff_renamesrc(struct apply_state *state,
	patch->old_name = find_name(state, line, NULL, state->p_value ? state->p_value - 1 : 0, 0);
static int gitdiff_renamedst(struct apply_state *state,
	patch->new_name = find_name(state, line, NULL, state->p_value ? state->p_value - 1 : 0, 0);
static int gitdiff_similarity(struct apply_state *state,
static int gitdiff_dissimilarity(struct apply_state *state,
static int gitdiff_index(struct apply_state *state,
	if (!ptr || ptr[1] != '.' || 40 < ptr - line)
	memcpy(patch->old_sha1_prefix, line, len);
	patch->old_sha1_prefix[len] = 0;
	if (40 < len)
	memcpy(patch->new_sha1_prefix, line, len);
	patch->new_sha1_prefix[len] = 0;
		patch->old_mode = strtoul(ptr+1, NULL, 8);
static int gitdiff_unrecognized(struct apply_state *state,
static const char *skip_tree_prefix(struct apply_state *state,
	if (!state->p_value)
	nslash = state->p_value;
static char *git_header_name(struct apply_state *state,
		cp = skip_tree_prefix(state, first.buf, first.len);
			cp = skip_tree_prefix(state, sp.buf, sp.len);
		cp = skip_tree_prefix(state, second, line + llen - second);
	name = skip_tree_prefix(state, line, llen);
			np = skip_tree_prefix(state, sp.buf, sp.len);
			second = skip_tree_prefix(state, name + len + 1,
/* Verify that we recognize the lines following a git header */
static int parse_git_header(struct apply_state *state,
			    const char *line,
			    int len,
			    unsigned int size,
			    struct patch *patch)
	patch->def_name = git_header_name(state, line, len);
	if (patch->def_name && state->root.len) {
		char *s = xstrfmt("%s%s", state->root.buf, patch->def_name);
	state->linenr++;
	for (offset = len ; size > 0 ; offset += len, size -= len, line += len, state->linenr++) {
			int (*fn)(struct apply_state *, const char *, struct patch *);
			res = p->fn(state, line + oplen, patch);
			int git_hdr_len = parse_git_header(state, line, len, size, patch);
			if (!patch->is_delete && !patch->new_name) {
	if (!deleted && !added)
	*name = xstrdup(prefix_filename(state->prefix, state->prefix_length, *name));
	if (0 < state->prefix_length) {
		int pathlen = strlen(pathname);
		if (pathlen <= state->prefix_length ||
		    memcmp(state->prefix, pathname, state->prefix_length))
		if (!wildmatch(it->string, pathname, 0, NULL))
		patch->ws_rule = whitespace_rule(patch->new_name
						 ? patch->new_name
						 : patch->old_name);
#define swap(a,b) myswap((a),(b),sizeof(a))

#define myswap(a, b, size) do {		\
	unsigned char mytmp[size];	\
	memcpy(mytmp, &a, size);		\
	memcpy(&a, &b, size);		\
	memcpy(&b, mytmp, size);		\
} while (0)

		swap(p->new_name, p->old_name);
		swap(p->new_mode, p->old_mode);
		swap(p->is_new, p->is_delete);
		swap(p->lines_added, p->lines_deleted);
		swap(p->old_sha1_prefix, p->new_sha1_prefix);
			swap(frag->newpos, frag->oldpos);
			swap(frag->newlines, frag->oldlines);
static int read_old_data(struct stat *st, const char *path, struct strbuf *buf)
		convert_to_git(path, buf->buf, buf->len, buf, 0);
	char *new, *old, *fixed;
	old = postimage->buf;
		new = postimage->buf = xmalloc(postlen);
		new = old;
			memmove(new, old, l_len);
			old += l_len;
			new += l_len;
		old += l_len;
		memcpy(new, fixed, l_len);
		new += l_len;
	    ? postlen < new - postimage->buf
	    : postimage->len < new - postimage->buf)
		die("BUG: caller miscounted postlen: asked %d, orig = %d, used = %d",
		    (int)postlen, (int) postimage->len, (int)(new - postimage->buf));
	postimage->len = new - postimage->buf;
				    unsigned long try,
				    int try_lno,
		size_t imglen = img->line[try_lno+i].len;
		if (!fuzzy_matchlines(img->buf + try + imgoff, imglen,
	strbuf_add(&fixed, img->buf + try, imgoff);
			  unsigned long try,
			  int try_lno,
	if (preimage->nr + try_lno <= img->nr) {
		if (match_end && (preimage->nr + try_lno != img->nr))
		preimage_limit = img->nr - try_lno;
	if (match_beginning && try_lno)
		if ((img->line[try_lno + i].flag & LINE_PATCHED) ||
		    (preimage->line[i].hash != img->line[try_lno + i].hash))
		 * at the end, size must be exactly at try+fragsize,
		 * otherwise try+fragsize must be still within the preimage,
		     ? (try + preimage->len == img->len)
		     : (try + preimage->len <= img->len)) &&
		    !memcmp(img->buf + try, preimage->buf, preimage->len))
						try, try_lno, preimage_limit);
	target = img->buf + try;
		size_t tgtlen = img->line[try_lno + i].len;
	unsigned long backwards, forwards, try;
	int backwards_lno, forwards_lno, try_lno;
	try = 0;
		try += img->line[i].len;
	backwards = try;
	forwards = try;
	try_lno = line;
				   try, try_lno, ws_rule,
			return try_lno;
			try = backwards;
			try_lno = backwards_lno;
			try = forwards;
			try_lno = forwards_lno;
		memmove(img->line + applied_pos + postimage->nr,
			img->line + applied_pos + preimage_limit,
			(img->nr - (applied_pos + preimage_limit)) *
			sizeof(*img->line));
	memcpy(img->line + applied_pos,
	       postimage->line,
	       postimage->nr * sizeof(*img->line));
		/* Fall-through for ' ' */
	 * full 40-byte textual SHA1 for old and new, at least for now.
	if (strlen(patch->old_sha1_prefix) != 40 ||
	    strlen(patch->new_sha1_prefix) != 40 ||
	    get_oid_hex(patch->old_sha1_prefix, &oid) ||
	    get_oid_hex(patch->new_sha1_prefix, &oid))
		hash_sha1_file(img->buf, img->len, blob_type, oid.hash);
		if (strcmp(oid_to_hex(&oid), patch->old_sha1_prefix))
	get_oid_hex(patch->new_sha1_prefix, &oid);
	if (has_sha1_file(oid.hash)) {
		result = read_sha1_file(oid.hash, &type, &size);
				     patch->new_sha1_prefix, name);
		hash_sha1_file(img->buf, img->len, blob_type, oid.hash);
		if (strcmp(oid_to_hex(&oid), patch->new_sha1_prefix))
				name, patch->new_sha1_prefix, oid_to_hex(&oid));
		result = read_sha1_file(oid->hash, &type, &sz);
	if (checkout_entry(ce, &costate, NULL) || lstat(ce->name, st))
static int verify_index_match(const struct cache_entry *ce, struct stat *st)
	return ce_match_stat(ce, st, CE_MATCH_IGNORE_VALID|CE_MATCH_IGNORE_SKIP_WORKTREE);
			if (read_old_data(st, name, buf))
		status = load_patch_target(state, &buf, ce, st,
static int three_way_merge(struct image *image,
			  &their_file, "theirs", NULL);
		die("BUG: patch to %s is not a creation", patch->old_name);
	pos = cache_name_pos(name, strlen(name));
	ce = active_cache[pos];
		if (checkout_target(&the_index, ce, &st))
	if (verify_index_match(ce, &st))
	status = load_patch_target(state, &buf, ce, &st, name, mode);
		write_sha1_file("", 0, blob_type, pre_oid.hash);
	else if (get_sha1(patch->old_sha1_prefix, pre_oid.hash) ||
	write_sha1_file(tmp_image.buf, tmp_image.len, blob_type, post_oid.hash);
	write_sha1_file(tmp_image.buf, tmp_image.len, blob_type, our_oid.hash);
	status = three_way_merge(image, patch->new_name,
		int pos = cache_name_pos(old_name, strlen(old_name));
		*ce = active_cache[pos];
			if (checkout_target(&the_index, *ce, st))
		if (!state->cached && verify_index_match(*ce, st))
	free(patch->old_name);
	patch->old_name = NULL;
	    cache_name_pos(new_name, strlen(new_name)) >= 0 &&
	} else if ((errno != ENOENT) && (errno != ENOTDIR)) {
			ce = cache_file_exists(name->buf, name->len, ignore_case);
		return read_cache_from(state->index_file);
		return read_cache();
	pos = cache_name_pos(path, strlen(path));
	oidcpy(oid, &active_cache[pos]->oid);
	    preimage[sizeof(heading) + GIT_SHA1_HEXSZ - 1] == '\n' &&
	    starts_with(preimage + sizeof(heading) - 1, p->old_sha1_prefix))
	return get_oid_hex(p->old_sha1_prefix, oid);
/* Build an index that contains the just the files needed for a 3way merge */
	static struct lock_file lock;
		} else if (!get_sha1_blob(patch->old_sha1_prefix, oid.hash)) {
		ce = make_cache_entry(patch->old_mode, oid.hash, name, 0, 0);
			free(ce);
	 if (res)
		 return error(_("could not write temporary index to %s"),
			      state->fake_ancestor);
	 return 0;
 }
 static void stat_patch_list(struct apply_state *state, struct patch *patch)
 {
	 int files, adds, dels;
	 for (files = adds = dels = 0 ; patch ; patch = patch->next) {
		 files++;
		 adds += patch->lines_added;
		 dels += patch->lines_deleted;
		 show_stats(state, patch);
	 }
	 print_stat_summary(stdout, files, adds, dels);
 }
 static void numstat_patch_list(struct apply_state *state,
				struct patch *patch)
 {
	 for ( ; patch; patch = patch->next) {
		 const char *name;
		 name = patch->new_name ? patch->new_name : patch->old_name;
		 if (patch->is_binary)
			 printf("-\t-\t");
		 else
			 printf("%d\t%d\t", patch->lines_added, patch->lines_deleted);
		 write_name_quoted(name, stdout, state->line_termination);
	 }
 }

 static void show_file_mode_name(const char *newdelete, unsigned int mode, const char *name)
 {
	 if (mode)
		 printf(" %s mode %06o %s\n", newdelete, mode, name);
	 else
		 printf(" %s %s\n", newdelete, name);
 }

 static void show_mode_change(struct patch *p, int show_name)
 {
	 if (p->old_mode && p->new_mode && p->old_mode != p->new_mode) {
		 if (show_name)
			 printf(" mode change %06o => %06o %s\n",
				p->old_mode, p->new_mode, p->new_name);
		 else
			 printf(" mode change %06o => %06o\n",
				p->old_mode, p->new_mode);
	 }
 }

 static void show_rename_copy(struct patch *p)
 {
	 const char *renamecopy = p->is_rename ? "rename" : "copy";
	 const char *old, *new;

	 /* Find common prefix */
	 old = p->old_name;
	 new = p->new_name;
	 while (1) {
		 const char *slash_old, *slash_new;
		 slash_old = strchr(old, '/');
		 slash_new = strchr(new, '/');
		 if (!slash_old ||
		     !slash_new ||
		     slash_old - old != slash_new - new ||
		     memcmp(old, new, slash_new - new))
			 break;
		 old = slash_old + 1;
		 new = slash_new + 1;
	 }
	 /* p->old_name thru old is the common prefix, and old and new
	  * through the end of names are renames
	  */
	 if (old != p->old_name)
		 printf(" %s %.*s{%s => %s} (%d%%)\n", renamecopy,
			(int)(old - p->old_name), p->old_name,
			old, new, p->score);
	 else
		 printf(" %s %s => %s (%d%%)\n", renamecopy,
			p->old_name, p->new_name, p->score);
	 show_mode_change(p, 0);
 }

 static void summary_patch_list(struct patch *patch)
 {
	 struct patch *p;

	 for (p = patch; p; p = p->next) {
		 if (p->is_new)
			 show_file_mode_name("create", p->new_mode, p->new_name);
		 else if (p->is_delete)
			 show_file_mode_name("delete", p->old_mode, p->old_name);
		 else {
			 if (p->is_rename || p->is_copy)
				 show_rename_copy(p);
			 else {
				 if (p->score) {
					 printf(" rewrite %s (%d%%)\n",
						p->new_name, p->score);
					 show_mode_change(p, 0);
				 }
				 else
					 show_mode_change(p, 1);
			 }
		 }
	 }
 }

 static void patch_stats(struct apply_state *state, struct patch *patch)
 {
	 int lines = patch->lines_added + patch->lines_deleted;

	 if (lines > state->max_change)
		 state->max_change = lines;
	 if (patch->old_name) {
		 int len = quote_c_style(patch->old_name, NULL, NULL, 0);
		 if (!len)
			 len = strlen(patch->old_name);
		 if (len > state->max_len)
			 state->max_len = len;
	 }
	 if (patch->new_name) {
		 int len = quote_c_style(patch->new_name, NULL, NULL, 0);
		 if (!len)
			 len = strlen(patch->new_name);
		 if (len > state->max_len)
			 state->max_len = len;
	 }
 }

 static int remove_file(struct apply_state *state, struct patch *patch, int rmdir_empty)
 {
	 if (state->update_index) {
		 if (remove_file_from_cache(patch->old_name) < 0)
			 return error(_("unable to remove %s from index"), patch->old_name);
	 }
	 if (!state->cached) {
		 if (!remove_or_warn(patch->old_mode, patch->old_name) && rmdir_empty) {
			 remove_path(patch->old_name);
		 }
	 }
	 return 0;
 }

 static int add_index_file(struct apply_state *state,
			   const char *path,
			   unsigned mode,
			   void *buf,
			   unsigned long size)
 {
	 struct stat st;
	 struct cache_entry *ce;
	 int namelen = strlen(path);
	 unsigned ce_size = cache_entry_size(namelen);

	 if (!state->update_index)
		 return 0;

	 ce = xcalloc(1, ce_size);
	 memcpy(ce->name, path, namelen);
	 ce->ce_mode = create_ce_mode(mode);
	 ce->ce_flags = create_ce_flags(0);
	 ce->ce_namelen = namelen;
	 if (S_ISGITLINK(mode)) {
		 const char *s;

		 if (!skip_prefix(buf, "Subproject commit ", &s) ||
		     get_oid_hex(s, &ce->oid)) {
			free(ce);
				free(ce);
			fill_stat_cache_info(ce, &st);
		if (write_sha1_file(buf, size, blob_type, ce->oid.hash) < 0) {
			free(ce);
	if (add_cache_entry(ce, ADD_CACHE_OK_TO_ADD) < 0) {
		free(ce);
static int try_create_file(const char *path, unsigned int mode, const char *buf, unsigned long size)
	if (convert_to_working_tree(path, buf, size, &nbuf)) {
	res = try_create_file(path, mode, buf, size);
		res = try_create_file(path, mode, buf, size);
			res = try_create_file(newpath, mode, buf, size);
	unsigned ce_size, mode;
	ce_size = cache_entry_size(namelen);
	remove_file_from_cache(patch->new_name);
		ce = xcalloc(1, ce_size);
		if (add_cache_entry(ce, ADD_CACHE_OK_TO_ADD) < 0) {
			free(ce);
	else
		rerere(0);
	state->update_index = state->check_index && state->apply;
	if (state->update_index && state->newfd < 0) {
			state->newfd = hold_lock_file_for_update(state->lock_file,
								 state->index_file,
								 LOCK_DIE_ON_ERROR);
			state->newfd = hold_locked_index(state->lock_file, 1);
		exit(1);
		} else if (0 < state->prefix_length)
			arg = prefix_filename(state->prefix,
					      state->prefix_length,
					      arg);
		res = write_locked_index(&the_index, state->lock_file, COMMIT_LOCK);
		state->newfd = -1;
	if (state->newfd >= 0) {
		rollback_lock_file(state->lock_file);
		state->newfd = -1;
	}
			0, apply_option_parse_exclude },
			0, apply_option_parse_include },
		OPT_BOOL(0, "unsafe-paths", &state->unsafe_paths,
			N_("accept a patch that touches outside the working area")),