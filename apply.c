#include "config.h"
#include "object-store.h"
struct gitdiff_data {
	struct strbuf *root;
	int linenr;
	int p_value;
};

	/*
	 * Please update $__git_whitespacelist in git-completion.bash
	 * when you add new options.
	 */
		     struct repository *repo,
		     const char *prefix)
	state->repo = repo;
	if (state->ita_only && (state->check_index || is_not_gitdir))
		state->ita_only = 0;
	const char *end1 = s1 + n1;
	const char *end2 = s2 + n2;
	while (s1 < end1 && (end1[-1] == '\r' || end1[-1] == '\n'))
		end1--;
	while (s2 < end2 && (end2[-1] == '\r' || end2[-1] == '\n'))
		end2--;

	while (s1 < end1 && s2 < end2) {
		if (isspace(*s1)) {
			/*
			 * Skip whitespace. We check on both buffers
			 * because we don't want "a b" to match "ab".
			 */
			if (!isspace(*s2))
				return 0;
			while (s1 < end1 && isspace(*s1))
			while (s2 < end2 && isspace(*s2))
		} else if (*s1++ != *s2++)
	/* If we reached the end on one side only, lines don't match. */
	return s1 == end1 && s2 == end2;
static char *find_name_gnu(struct strbuf *root,
	 * https://public-inbox.org/git/7vll0wvb2a.fsf@assigned-by-dhcp.cox.net/
	if (root->len)
		strbuf_insert(&name, 0, root->buf, root->len);
static char *find_name_common(struct strbuf *root,
	if (root->len) {
		char *ret = xstrfmt("%s%.*s", root->buf, len, start);
static char *find_name(struct strbuf *root,
		char *name = find_name_gnu(root, line, p_value);
	return find_name_common(root, line, def, p_value, NULL, terminate);
static char *find_name_traditional(struct strbuf *root,
		char *name = find_name_gnu(root, line, p_value);
		return find_name_common(root, line, def, p_value, NULL, TERM_TAB);
	return find_name_common(root, line, def, p_value, line + len, 0);
	name = find_name_traditional(&state->root, nameline, NULL, 0);
		if (starts_with(name, state->prefix))
			if (starts_with(cp, state->prefix))
		"^[0-2][0-9]:([0-5][0-9]):00(\\.0+)?"
	int zoneoffset, epoch_hour, hour, minute;

	/*
	 * YYYY-MM-DD hh:mm:ss must be from either 1969-12-31
	 * (west of GMT) or 1970-01-01 (east of GMT)
	 */
	if (skip_prefix(timestamp, "1969-12-31 ", &timestamp))
		epoch_hour = 24;
	else if (skip_prefix(timestamp, "1970-01-01 ", &timestamp))
		epoch_hour = 0;
	else
		return 0;

	hour = strtol(timestamp, NULL, 10);
	minute = strtol(timestamp + m[1].rm_so, NULL, 10);

	return hour * 60 + minute - zoneoffset == epoch_hour * 60;
		name = find_name_traditional(&state->root, second, NULL, state->p_value);
		name = find_name_traditional(&state->root, first, NULL, state->p_value);
		first_name = find_name_traditional(&state->root, first, NULL, state->p_value);
		name = find_name_traditional(&state->root, second, first_name, state->p_value);
static int gitdiff_hdrend(struct gitdiff_data *state,
static int gitdiff_verify_name(struct gitdiff_data *state,
		*name = find_name(state->root, line, NULL, state->p_value, TERM_TAB);
		another = find_name(state->root, line, NULL, state->p_value, TERM_TAB);
		if (!another || strcmp(another, *name)) {
		if (!is_dev_null(line))
static int gitdiff_oldname(struct gitdiff_data *state,
static int gitdiff_newname(struct gitdiff_data *state,
static int parse_mode_line(const char *line, int linenr, unsigned int *mode)
{
	char *end;
	*mode = strtoul(line, &end, 8);
	if (end == line || !isspace(*end))
		return error(_("invalid mode on line %d: %s"), linenr, line);
	return 0;
}

static int gitdiff_oldmode(struct gitdiff_data *state,
	return parse_mode_line(line, state->linenr, &patch->old_mode);
static int gitdiff_newmode(struct gitdiff_data *state,
	return parse_mode_line(line, state->linenr, &patch->new_mode);
static int gitdiff_delete(struct gitdiff_data *state,
static int gitdiff_newfile(struct gitdiff_data *state,
static int gitdiff_copysrc(struct gitdiff_data *state,
	patch->old_name = find_name(state->root, line, NULL, state->p_value ? state->p_value - 1 : 0, 0);
static int gitdiff_copydst(struct gitdiff_data *state,
	patch->new_name = find_name(state->root, line, NULL, state->p_value ? state->p_value - 1 : 0, 0);
static int gitdiff_renamesrc(struct gitdiff_data *state,
	patch->old_name = find_name(state->root, line, NULL, state->p_value ? state->p_value - 1 : 0, 0);
static int gitdiff_renamedst(struct gitdiff_data *state,
	patch->new_name = find_name(state->root, line, NULL, state->p_value ? state->p_value - 1 : 0, 0);
static int gitdiff_similarity(struct gitdiff_data *state,
static int gitdiff_dissimilarity(struct gitdiff_data *state,
static int gitdiff_index(struct gitdiff_data *state,
	const unsigned hexsz = the_hash_algo->hexsz;
	if (!ptr || ptr[1] != '.' || hexsz < ptr - line)
	memcpy(patch->old_oid_prefix, line, len);
	patch->old_oid_prefix[len] = 0;
	if (hexsz < len)
	memcpy(patch->new_oid_prefix, line, len);
	patch->new_oid_prefix[len] = 0;
		return gitdiff_oldmode(state, ptr + 1, patch);
static int gitdiff_unrecognized(struct gitdiff_data *state,
static const char *skip_tree_prefix(int p_value,
	if (!p_value)
	nslash = p_value;
static char *git_header_name(int p_value,
		cp = skip_tree_prefix(p_value, first.buf, first.len);
			cp = skip_tree_prefix(p_value, sp.buf, sp.len);
		cp = skip_tree_prefix(p_value, second, line + llen - second);
	name = skip_tree_prefix(p_value, line, llen);
			np = skip_tree_prefix(p_value, sp.buf, sp.len);
			second = skip_tree_prefix(p_value, name + len + 1,
static int check_header_line(int linenr, struct patch *patch)
{
	int extensions = (patch->is_delete == 1) + (patch->is_new == 1) +
			 (patch->is_rename == 1) + (patch->is_copy == 1);
	if (extensions > 1)
		return error(_("inconsistent header lines %d and %d"),
			     patch->extension_linenr, linenr);
	if (extensions && !patch->extension_linenr)
		patch->extension_linenr = linenr;
	return 0;
}

int parse_git_diff_header(struct strbuf *root,
			  int *linenr,
			  int p_value,
			  const char *line,
			  int len,
			  unsigned int size,
			  struct patch *patch)
	struct gitdiff_data parse_hdr_state;
	patch->def_name = git_header_name(p_value, line, len);
	if (patch->def_name && root->len) {
		char *s = xstrfmt("%s%s", root->buf, patch->def_name);
	(*linenr)++;
	parse_hdr_state.root = root;
	parse_hdr_state.linenr = *linenr;
	parse_hdr_state.p_value = p_value;

	for (offset = len ; size > 0 ; offset += len, size -= len, line += len, (*linenr)++) {
			int (*fn)(struct gitdiff_data *, const char *, struct patch *);
			res = p->fn(&parse_hdr_state, line + oplen, patch);
			if (check_header_line(*linenr, patch))
				return -1;
				goto done;
done:
	if (!patch->old_name && !patch->new_name) {
		if (!patch->def_name) {
			error(Q_("git diff header lacks filename information when removing "
				 "%d leading pathname component (line %d)",
				 "git diff header lacks filename information when removing "
				 "%d leading pathname components (line %d)",
				 parse_hdr_state.p_value),
			      parse_hdr_state.p_value, *linenr);
			return -128;
		}
		patch->old_name = xstrdup(patch->def_name);
		patch->new_name = xstrdup(patch->def_name);
	}
	if ((!patch->new_name && !patch->is_delete) ||
	    (!patch->old_name && !patch->is_new)) {
		error(_("git diff header lacks filename information "
			"(line %d)"), *linenr);
		return -128;
	}
	patch->is_toplevel_relative = 1;
			int git_hdr_len = parse_git_diff_header(&state->root, &state->linenr,
								state->p_value, line, len,
								size, patch);
/*
 * Check if the patch has context lines with CRLF or
 * the patch wants to remove lines with CRLF.
 */
static void check_old_for_crlf(struct patch *patch, const char *line, int len)
{
	if (len >= 2 && line[len-1] == '\n' && line[len-2] == '\r') {
		patch->ws_rule |= WS_CR_AT_EOL;
		patch->crlf_in_old = 1;
	}
}


			check_old_for_crlf(patch, line, len);
			if (!state->apply_in_reverse)
				check_old_for_crlf(patch, line, len);
			if (state->apply_in_reverse)
				check_old_for_crlf(patch, line, len);
	if (!patch->recount && !deleted && !added)
	*name = prefix_filename(state->prefix, *name);
	if (state->prefix && *state->prefix) {
		const char *rest;
		if (!skip_prefix(pathname, state->prefix, &rest) || !*rest)
		if (!wildmatch(it->string, pathname, 0))
	else if (patch->new_name)
		patch->ws_rule = whitespace_rule(state->repo->index,
						 patch->new_name);
		patch->ws_rule = whitespace_rule(state->repo->index,
						 patch->old_name);
		SWAP(p->new_name, p->old_name);
		SWAP(p->new_mode, p->old_mode);
		SWAP(p->is_new, p->is_delete);
		SWAP(p->lines_added, p->lines_deleted);
		SWAP(p->old_oid_prefix, p->new_oid_prefix);
			SWAP(frag->newpos, frag->oldpos);
			SWAP(frag->newlines, frag->oldlines);
static int read_old_data(struct stat *st, struct patch *patch,
			 const char *path, struct strbuf *buf)
	int conv_flags = patch->crlf_in_old ?
		CONV_EOL_KEEP_CRLF : CONV_EOL_RENORMALIZE;
		/*
		 * "git apply" without "--index/--cached" should never look
		 * at the index; the target file may not have been added to
		 * the index yet, and we may not even be in any Git repository.
		 * Pass NULL to convert_to_git() to stress this; the function
		 * should never look at the index when explicit crlf option
		 * is given.
		 */
		convert_to_git(NULL, path, buf->buf, buf->len, buf, conv_flags);
	char *new_buf, *old_buf, *fixed;
	old_buf = postimage->buf;
		new_buf = postimage->buf = xmalloc(postlen);
		new_buf = old_buf;
			memmove(new_buf, old_buf, l_len);
			old_buf += l_len;
			new_buf += l_len;
		old_buf += l_len;
		memcpy(new_buf, fixed, l_len);
		new_buf += l_len;
	    ? postlen < new_buf - postimage->buf
	    : postimage->len < new_buf - postimage->buf)
		BUG("caller miscounted postlen: asked %d, orig = %d, used = %d",
		    (int)postlen, (int) postimage->len, (int)(new_buf - postimage->buf));
	postimage->len = new_buf - postimage->buf;
				    unsigned long current,
				    int current_lno,
		size_t imglen = img->line[current_lno+i].len;
		if (!fuzzy_matchlines(img->buf + current + imgoff, imglen,
	strbuf_add(&fixed, img->buf + current, imgoff);
			  unsigned long current,
			  int current_lno,
	if (preimage->nr + current_lno <= img->nr) {
		if (match_end && (preimage->nr + current_lno != img->nr))
		preimage_limit = img->nr - current_lno;
	if (match_beginning && current_lno)
		if ((img->line[current_lno + i].flag & LINE_PATCHED) ||
		    (preimage->line[i].hash != img->line[current_lno + i].hash))
		 * at the end, size must be exactly at current+fragsize,
		 * otherwise current+fragsize must be still within the preimage,
		     ? (current + preimage->len == img->len)
		     : (current + preimage->len <= img->len)) &&
		    !memcmp(img->buf + current, preimage->buf, preimage->len))
						current, current_lno, preimage_limit);
	target = img->buf + current;
		size_t tgtlen = img->line[current_lno + i].len;
	unsigned long backwards, forwards, current;
	int backwards_lno, forwards_lno, current_lno;
	current = 0;
		current += img->line[i].len;
	backwards = current;
	forwards = current;
	current_lno = line;
				   current, current_lno, ws_rule,
			return current_lno;
			current = backwards;
			current_lno = backwards_lno;
			current = forwards;
			current_lno = forwards_lno;
		MOVE_ARRAY(img->line + applied_pos + postimage->nr,
			   img->line + applied_pos + preimage_limit,
			   img->nr - (applied_pos + preimage_limit));
	COPY_ARRAY(img->line + applied_pos, postimage->line, postimage->nr);
			/* fallthrough */
			/* fallthrough */
		preimage.line_allocated[preimage.nr - 1].len--;
		postimage.line_allocated[postimage.nr - 1].len--;
	const unsigned hexsz = the_hash_algo->hexsz;
	 * full hex textual object ID for old and new, at least for now.
	if (strlen(patch->old_oid_prefix) != hexsz ||
	    strlen(patch->new_oid_prefix) != hexsz ||
	    get_oid_hex(patch->old_oid_prefix, &oid) ||
	    get_oid_hex(patch->new_oid_prefix, &oid))
		hash_object_file(img->buf, img->len, blob_type, &oid);
		if (strcmp(oid_to_hex(&oid), patch->old_oid_prefix))
	get_oid_hex(patch->new_oid_prefix, &oid);
	if (has_object_file(&oid)) {
		result = read_object_file(&oid, &type, &size);
				     patch->new_oid_prefix, name);
		hash_object_file(img->buf, img->len, blob_type, &oid);
		if (strcmp(oid_to_hex(&oid), patch->new_oid_prefix))
				name, patch->new_oid_prefix, oid_to_hex(&oid));
		result = read_object_file(oid, &type, &sz);
	if (checkout_entry(ce, &costate, NULL, NULL) ||
	    lstat(ce->name, st))
static int verify_index_match(struct apply_state *state,
			      const struct cache_entry *ce,
			      struct stat *st)
	return ie_match_stat(state->repo->index, ce, st,
			     CE_MATCH_IGNORE_VALID | CE_MATCH_IGNORE_SKIP_WORKTREE);
			     struct patch *patch,
			if (read_old_data(st, patch, name, buf))
		status = load_patch_target(state, &buf, ce, st, patch,
static int three_way_merge(struct apply_state *state,
			   struct image *image,
			  &their_file, "theirs",
			  state->repo->index,
			  NULL);
		BUG("patch to %s is not a creation", patch->old_name);
	pos = index_name_pos(state->repo->index, name, strlen(name));
	ce = state->repo->index->cache[pos];
		if (checkout_target(state->repo->index, ce, &st))
	if (verify_index_match(state, ce, &st))
	status = load_patch_target(state, &buf, ce, &st, patch, name, mode);
		write_object_file("", 0, blob_type, &pre_oid);
	else if (get_oid(patch->old_oid_prefix, &pre_oid) ||
	write_object_file(tmp_image.buf, tmp_image.len, blob_type, &post_oid);
	write_object_file(tmp_image.buf, tmp_image.len, blob_type, &our_oid);
	status = three_way_merge(state, image, patch->new_name,
		int pos = index_name_pos(state->repo->index, old_name,
					 strlen(old_name));
		*ce = state->repo->index->cache[pos];
			if (checkout_target(state->repo->index, *ce, st))
		if (!state->cached && verify_index_match(state, *ce, st))
	FREE_AND_NULL(patch->old_name);
	    index_name_pos(state->repo->index, new_name, strlen(new_name)) >= 0 &&
	} else if (!is_missing_file_error(errno)) {
			ce = index_file_exists(state->repo->index, name->buf,
					       name->len, ignore_case);
		return read_index_from(state->repo->index, state->index_file,
				       get_git_dir());
		return repo_read_index(state->repo);
	pos = index_name_pos(state->repo->index, path, strlen(path));
	oidcpy(oid, &state->repo->index->cache[pos]->oid);
	    preimage[sizeof(heading) + the_hash_algo->hexsz - 1] == '\n' &&
	    starts_with(preimage + sizeof(heading) - 1, p->old_oid_prefix))
	return get_oid_hex(p->old_oid_prefix, oid);
/* Build an index that contains just the files needed for a 3way merge */
	struct lock_file lock = LOCK_INIT;
		} else if (!get_oid_blob(patch->old_oid_prefix, &oid)) {
		ce = make_cache_entry(&result, patch->old_mode, &oid, name, 0, 0);
			discard_cache_entry(ce);
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
	const char *old_name, *new_name;

	/* Find common prefix */
	old_name = p->old_name;
	new_name = p->new_name;
	while (1) {
		const char *slash_old, *slash_new;
		slash_old = strchr(old_name, '/');
		slash_new = strchr(new_name, '/');
		if (!slash_old ||
		    !slash_new ||
		    slash_old - old_name != slash_new - new_name ||
		    memcmp(old_name, new_name, slash_new - new_name))
			break;
		old_name = slash_old + 1;
		new_name = slash_new + 1;
	}
	/* p->old_name thru old_name is the common prefix, and old_name and new_name
	 * through the end of names are renames
	 */
	if (old_name != p->old_name)
		printf(" %s %.*s{%s => %s} (%d%%)\n", renamecopy,
		       (int)(old_name - p->old_name), p->old_name,
		       old_name, new_name, p->score);
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
	if (state->update_index && !state->ita_only) {
		if (remove_file_from_index(state->repo->index, patch->old_name) < 0)
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

	ce = make_empty_cache_entry(state->repo->index, namelen);
	memcpy(ce->name, path, namelen);
	ce->ce_mode = create_ce_mode(mode);
	ce->ce_flags = create_ce_flags(0);
	ce->ce_namelen = namelen;
	if (state->ita_only) {
		ce->ce_flags |= CE_INTENT_TO_ADD;
		set_object_name_for_intent_to_add_entry(ce);
	} else if (S_ISGITLINK(mode)) {
		const char *s;

		if (!skip_prefix(buf, "Subproject commit ", &s) ||
		    get_oid_hex(s, &ce->oid)) {
			discard_cache_entry(ce);
				discard_cache_entry(ce);
			fill_stat_cache_info(state->repo->index, ce, &st);
		if (write_object_file(buf, size, blob_type, &ce->oid) < 0) {
			discard_cache_entry(ce);
	if (add_index_entry(state->repo->index, ce, ADD_CACHE_OK_TO_ADD) < 0) {
		discard_cache_entry(ce);
static int try_create_file(struct apply_state *state, const char *path,
			   unsigned int mode, const char *buf,
			   unsigned long size)
	if (convert_to_working_tree(state->repo->index, path, buf, size, &nbuf)) {
	res = try_create_file(state, path, mode, buf, size);
		res = try_create_file(state, path, mode, buf, size);
			res = try_create_file(state, newpath, mode, buf, size);
	unsigned mode;
	remove_file_from_index(state->repo->index, patch->new_name);
		ce = make_empty_cache_entry(state->repo->index, namelen);
		if (add_index_entry(state->repo->index, ce, ADD_CACHE_OK_TO_ADD) < 0) {
			discard_cache_entry(ce);
	else if (state->update_index)
	return 0;
		repo_rerere(state->repo, 0);
	int flush_attributes = 0;

			if ((patch->new_name &&
			     ends_with_path_components(patch->new_name,
						       GITATTRIBUTES_FILE)) ||
			    (patch->old_name &&
			     ends_with_path_components(patch->old_name,
						       GITATTRIBUTES_FILE)))
				flush_attributes = 1;
	state->update_index = (state->check_index || state->ita_only) && state->apply;
	if (state->update_index && !is_lock_file_locked(&state->lock_file)) {
			hold_lock_file_for_update(&state->lock_file,
						  state->index_file,
						  LOCK_DIE_ON_ERROR);
			repo_hold_locked_index(state->repo, &state->lock_file,
					       LOCK_DIE_ON_ERROR);
	if (flush_attributes)
		reset_parsed_attributes();

	BUG_ON_OPT_NEG(unset);


	BUG_ON_OPT_NEG(unset);


	BUG_ON_OPT_NEG(unset);


	BUG_ON_OPT_ARG(arg);


	BUG_ON_OPT_NEG(unset);

		return -1;

	BUG_ON_OPT_NEG(unset);

		char *to_free = NULL;
		} else
			arg = to_free = prefix_filename(state->prefix, arg);
			free(to_free);
		free(to_free);
		res = write_locked_index(state->repo->index, &state->lock_file, COMMIT_LOCK);
	rollback_lock_file(&state->lock_file);
			PARSE_OPT_NONEG, apply_option_parse_exclude },
			PARSE_OPT_NONEG, apply_option_parse_include },
		OPT_BOOL('N', "intent-to-add", &state->ita_only,
			N_("mark new files with `git add --intent-to-add`")),
		OPT_BOOL_F(0, "unsafe-paths", &state->unsafe_paths,
			   N_("accept a patch that touches outside the working area"),
			   PARSE_OPT_NOCOMPLETE),