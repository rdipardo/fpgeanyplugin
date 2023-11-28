{%MainUnit geanyplugin240.pp}

const
  External_library = 'libgeany.so.0'; {Setup as you need}


{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}

type
  time_t = clonglong;
  gintptr = coff_t;
  guintptr = culonglong;
  TTMParserType = gint;
  PGeanyFiletypePrivate = gpointer;
  PGeanyDocumentPrivate = gpointer;
  PGeanyProjectPrivate = gpointer;
  PGeanyPluginPrivate = gpointer;
  TBuildTableData = gpointer;
  TGeanyDocumentMessage = (MSG_TYPE_RELOAD, MSG_TYPE_RESAVE, MSG_TYPE_POST_RELOAD);

const
  NUM_MSG_TYPES = Ord(High(TGeanyDocumentMessage));
  GEANY_PROXY_IGNORE = $00;
  GEANY_PROXY_MATCH = $01;
  GEANY_PROXY_RELATED = (GEANY_PROXY_MATCH or $100);

{$IFDEF FPC}
{$ScopedEnums ON}
{$ENDIF}


type
  PSci_Position = ^TSci_Position;
  TSci_Position = coff_t;

  PSci_PositionU = ^TSci_PositionU;
  TSci_PositionU = culonglong;

  PSci_PositionCR = ^TSci_PositionCR;
  TSci_PositionCR = longint;

function Scintilla_LinkLexers: longint;cdecl;external External_library name 'Scintilla_LinkLexers';

type
  Puptr_t = ^culonglong;

  Psptr_t = ^coff_t;

  TSciFnDirect = function (ptr:coff_t; iMessage:dword; wParam:culonglong; lParam:coff_t): coff_t;cdecl;
  PSci_CharacterRange = ^TSci_CharacterRange;
  TSci_CharacterRange = record
    cpMin : TSci_PositionCR;
    cpMax : TSci_PositionCR;
  end;

  PSci_TextRange = ^TSci_TextRange;
  TSci_TextRange = record
    chrg : TSci_CharacterRange;
    lpstrText : Pchar;
  end;

  PSci_TextToFind = ^TSci_TextToFind;
  TSci_TextToFind = record
    chrg : TSci_CharacterRange;
    lpstrText : Pchar;
    chrgText : TSci_CharacterRange;
  end;


  PSci_SurfaceID = ^TSci_SurfaceID;
  TSci_SurfaceID = pointer;
  PSci_Rectangle = ^TSci_Rectangle;
  TSci_Rectangle = record
    left : longint;
    top : longint;
    right : longint;
    bottom : longint;
  end;

  PSci_RangeToFormat = ^TSci_RangeToFormat;
  TSci_RangeToFormat = record
    hdc : TSci_SurfaceID;
    hdcTarget : TSci_SurfaceID;
    rc : TSci_Rectangle;
    rcPage : TSci_Rectangle;
    chrg : TSci_CharacterRange;
  end;

  PSci_NotifyHeader = ^TSci_NotifyHeader;
  TSci_NotifyHeader = record
    hwndFrom : pointer;
    idFrom : culonglong;
    code : dword;
  end;

  PSCNotification = ^TSCNotification;
  TSCNotification = record
    nmhdr : TSci_NotifyHeader;
    position : TSci_Position;
    ch : longint;
    modifiers : longint;
    modificationType : longint;
    text : Pchar;
    length : TSci_Position;
    linesAdded : TSci_Position;
    message : longint;
    wParam : culonglong;
    lParam : coff_t;
    line : TSci_Position;
    foldLevelNow : longint;
    foldLevelPrev : longint;
    margin : longint;
    listType : longint;
    x : longint;
    y : longint;
    token : longint;
    annotationLinesAdded : TSci_Position;
    updated : longint;
    listCompletionMethod : longint;
    characterSource : longint;
  end;

  PScintillaObject = ^TScintillaObject;
  TScintillaObject = record
    cont : TGtkContainer;
    pscin : pointer;
  end;

  PScintillaClass = ^TScintillaClass;
  TScintillaClass = record
    parent_class : TGtkContainerClass;
    command : procedure (var sci:TScintillaObject; cmd:longint; var window:TGtkWidget);cdecl;
    notify : procedure (var sci:TScintillaObject; id:longint; var scn:TSCNotification);cdecl;
  end;


function scintilla_object_get_type: TGType;cdecl;external External_library name 'scintilla_object_get_type';
function scintilla_object_new: PGtkWidget;cdecl;external External_library name 'scintilla_object_new';
function scintilla_object_send_message(var sci:TScintillaObject; iMessage:dword; wParam:guintptr; lParam:gintptr):
                                                                                                                 gintptr
;cdecl;external External_library name 'scintilla_object_send_message';
function scnotification_get_type: TGType;cdecl;external External_library name 'scnotification_get_type';
function scintilla_get_type: TGType;cdecl;external External_library name 'scintilla_get_type';
function scintilla_new: PGtkWidget;cdecl;external External_library name 'scintilla_new';
procedure scintilla_set_id(var sci:TScintillaObject; id:culonglong);cdecl;external External_library name
'scintilla_set_id';
function scintilla_send_message(var sci:TScintillaObject; iMessage:dword; wParam:culonglong; lParam:coff_t): coff_t;
cdecl;external External_library name 'scintilla_send_message';
procedure scintilla_release_resources;cdecl;external External_library name 'scintilla_release_resources';

type
  PTMTagType = ^TTMTagType;
  TTMTagType = (tm_tag_undef_t := 0,tm_tag_class_t := 1,
                tm_tag_enum_t := 2,tm_tag_enumerator_t := 4,
                tm_tag_field_t := 8,tm_tag_function_t := 16,
                tm_tag_interface_t := 32,tm_tag_member_t := 64,
                tm_tag_method_t := 128,tm_tag_namespace_t := 256,
                tm_tag_package_t := 512,tm_tag_prototype_t := 1024,
                tm_tag_struct_t := 2048,tm_tag_typedef_t := 4096,
                tm_tag_union_t := 8192,tm_tag_variable_t := 16384,
                tm_tag_externvar_t := 32768,tm_tag_macro_t := 65536,
                tm_tag_macro_with_arg_t := 131072,tm_tag_file_t := 262144,
                tm_tag_other_t := 524288,tm_tag_max_t := 1048575
               );


  PTMSourceFile = ^TTMSourceFile;
  TTMSourceFile = record
    lang : TTMParserType;
    file_name : Pchar;
    short_name : Pchar;
    tags_array : PGPtrArray;
  end;

function tm_source_file_get_type: TGType;cdecl;external External_library name 'tm_source_file_get_type';
function tm_source_file_new(file_name:Pchar; name:Pchar): PTMSourceFile;cdecl;external External_library name
'tm_source_file_new';
procedure tm_source_file_free(var source_file:TTMSourceFile);cdecl;external External_library name 'tm_source_file_free';

type
  PTMTagAttrType = ^TTMTagAttrType;
  TTMTagAttrType = (tm_tag_attr_none_t := 0,tm_tag_attr_name_t := 1,
                    tm_tag_attr_type_t := 2,tm_tag_attr_file_t := 4,
                    tm_tag_attr_line_t := 8,tm_tag_attr_pos_t := 16,
                    tm_tag_attr_scope_t := 32,tm_tag_attr_inheritance_t := 64,
                    tm_tag_attr_arglist_t := 128,tm_tag_attr_local_t := 256,
                    tm_tag_attr_time_t := 512,tm_tag_attr_vartype_t := 1024,
                    tm_tag_attr_access_t := 2048,tm_tag_attr_impl_t := 4096,
                    tm_tag_attr_lang_t := 8192,tm_tag_attr_inactive_t := 16384,
                    tm_tag_attr_pointer_t := 32768,tm_tag_attr_max_t := 65535
                   );

  PTMTag = ^TTMTag;
  TTMTag = record
    name : Pchar;
    _type : TTMTagType;
    refcount : gint;
    _file : PTMSourceFile;
    line : gulong;
    local : gboolean;
    pointerOrder : guint;
    arglist : Pchar;
    scope : Pchar;
    inheritance : Pchar;
    var_type : Pchar;
    access : char;
    impl : char;
    lang : TTMParserType;
  end;

function tm_tag_get_type: TGType;cdecl;external External_library name 'tm_tag_get_type';

type
  PTMWorkspace = ^TTMWorkspace;
  TTMWorkspace = record
    global_tags : PGPtrArray;
    source_files : PGPtrArray;
    tags_array : PGPtrArray;
    typename_array : PGPtrArray;
    global_typename_array : PGPtrArray;
  end;

procedure tm_workspace_add_source_file(var source_file:TTMSourceFile);cdecl;external External_library name
'tm_workspace_add_source_file';
procedure tm_workspace_remove_source_file(var source_file:TTMSourceFile);cdecl;external External_library name
'tm_workspace_remove_source_file';
procedure tm_workspace_add_source_files(var source_files:TGPtrArray);cdecl;external External_library name
'tm_workspace_add_source_files';
procedure tm_workspace_remove_source_files(var source_files:TGPtrArray);cdecl;external External_library name
'tm_workspace_remove_source_files';

type
  PGeanyProject = ^TGeanyProject;
  TGeanyProject = record
    name : Pgchar;
    description : Pgchar;
    file_name : Pgchar;
    base_path : Pgchar;
    _type : gint;
    file_patterns : TGStrv;
    priv : PGeanyProjectPrivate;
  end;

procedure project_write_config;cdecl;external External_library name 'project_write_config';

type
  PGeanyApp = ^TGeanyApp;
  TGeanyApp = record
    debug_mode : gboolean;
    configdir : Pgchar;
    datadir : Pgchar;
    docdir : Pgchar;
    tm_workspace : PTMWorkspace;
    project : PGeanyProject;
  end;

  PGeanyFiletypeID = ^TGeanyFiletypeID;
  TGeanyFiletypeID = (GEANY_FILETYPES_NONE := 0,GEANY_FILETYPES_PHP,
                      GEANY_FILETYPES_BASIC,GEANY_FILETYPES_MATLAB,
                      GEANY_FILETYPES_RUBY,GEANY_FILETYPES_LUA,
                      GEANY_FILETYPES_FERITE,GEANY_FILETYPES_YAML,
                      GEANY_FILETYPES_C,GEANY_FILETYPES_NSIS,
                      GEANY_FILETYPES_GLSL,GEANY_FILETYPES_PO,
                      GEANY_FILETYPES_MAKE,GEANY_FILETYPES_TCL,
                      GEANY_FILETYPES_XML,GEANY_FILETYPES_CSS,
                      GEANY_FILETYPES_REST,GEANY_FILETYPES_HASKELL,
                      GEANY_FILETYPES_JAVA,GEANY_FILETYPES_CAML,
                      GEANY_FILETYPES_AS,GEANY_FILETYPES_R,GEANY_FILETYPES_DIFF,
                      GEANY_FILETYPES_HTML,GEANY_FILETYPES_PYTHON,
                      GEANY_FILETYPES_CS,GEANY_FILETYPES_PERL,
                      GEANY_FILETYPES_VALA,GEANY_FILETYPES_PASCAL,
                      GEANY_FILETYPES_LATEX,GEANY_FILETYPES_ASM,
                      GEANY_FILETYPES_CONF,GEANY_FILETYPES_HAXE,
                      GEANY_FILETYPES_CPP,GEANY_FILETYPES_SH,
                      GEANY_FILETYPES_FORTRAN,GEANY_FILETYPES_SQL,
                      GEANY_FILETYPES_F77,GEANY_FILETYPES_DOCBOOK,
                      GEANY_FILETYPES_D,GEANY_FILETYPES_JS,GEANY_FILETYPES_VHDL,
                      GEANY_FILETYPES_ADA,GEANY_FILETYPES_CMAKE,
                      GEANY_FILETYPES_MARKDOWN,GEANY_FILETYPES_TXT2TAGS,
                      GEANY_FILETYPES_ABC,GEANY_FILETYPES_VERILOG,
                      GEANY_FILETYPES_FORTH,GEANY_FILETYPES_LISP,
                      GEANY_FILETYPES_ERLANG,GEANY_FILETYPES_COBOL,
                      GEANY_FILETYPES_OBJECTIVEC,GEANY_FILETYPES_ASCIIDOC,
                      GEANY_FILETYPES_ABAQUS,GEANY_FILETYPES_BATCH,
                      GEANY_FILETYPES_POWERSHELL,GEANY_FILETYPES_RUST,
                      GEANY_FILETYPES_COFFEESCRIPT,GEANY_FILETYPES_GO,
                      GEANY_FILETYPES_ZEPHIR,GEANY_FILETYPES_BIBTEX,
                      GEANY_FILETYPES_SMALLTALK,GEANY_FILETYPES_JULIA,
                      GEANY_MAX_BUILT_IN_FILETYPES);

  Pfiletype_id = ^Tfiletype_id;
  Tfiletype_id = TGeanyFiletypeID;

  PGeanyFiletypeGroupID = ^TGeanyFiletypeGroupID;
  TGeanyFiletypeGroupID = (GEANY_FILETYPE_GROUP_NONE,GEANY_FILETYPE_GROUP_COMPILED,
                           GEANY_FILETYPE_GROUP_SCRIPT,GEANY_FILETYPE_GROUP_MARKUP,
                           GEANY_FILETYPE_GROUP_MISC,GEANY_FILETYPE_GROUP_COUNT
                          );

  PGeanyFiletype = ^TGeanyFiletype;
  TGeanyFiletype = record
    id : TGeanyFiletypeID;
    lang : TTMParserType;
    name : Pgchar;
    title : Pgchar;
    extension : Pgchar;
    pattern : Pgchar;
    context_action_cmd : Pgchar;
    comment_open : Pgchar;
    comment_close : Pgchar;
    comment_use_indent : gboolean;
    group : TGeanyFiletypeGroupID;
    error_regex_string : Pgchar;
    lexer_filetype : PGeanyFiletype;
    mime_type : Pgchar;
    icon : PGIcon;
    comment_single : Pgchar;
    indent_type : gint;
    indent_width : gint;
    priv : PGeanyFiletypePrivate;
  end;

function filetypes_detect_from_file(utf8_filename:Pgchar): PGeanyFiletype;cdecl;external External_library name
'filetypes_detect_from_file';
function filetypes_lookup_by_name(name:Pgchar): PGeanyFiletype;cdecl;external External_library name
'filetypes_lookup_by_name';
function filetypes_index(idx:gint): PGeanyFiletype;cdecl;external External_library name 'filetypes_index';
function filetypes_get_display_name(var ft:TGeanyFiletype): Pgchar;cdecl;external External_library name
'filetypes_get_display_name';
function filetypes_get_sorted_by_name: PGSList;cdecl;external External_library name 'filetypes_get_sorted_by_name';
function filetype_get_type: TGType;cdecl;external External_library name 'filetype_get_type';

type
  PGeanyIndentType = ^TGeanyIndentType;
  TGeanyIndentType = (GEANY_INDENT_TYPE_SPACES,GEANY_INDENT_TYPE_TABS,
                      GEANY_INDENT_TYPE_BOTH);

  PGeanyAutoIndent = ^TGeanyAutoIndent;
  TGeanyAutoIndent = (GEANY_AUTOINDENT_NONE := 0,GEANY_AUTOINDENT_BASIC,
                      GEANY_AUTOINDENT_CURRENTCHARS,GEANY_AUTOINDENT_MATCHBRACES
                     );

  PGeanyIndicator = ^TGeanyIndicator;
  TGeanyIndicator = (GEANY_INDICATOR_ERROR := 0,GEANY_INDICATOR_SEARCH := 8,
                     GEANY_INDICATOR_SNIPPET := 9);

  PGeanyIndentPrefs = ^TGeanyIndentPrefs;
  TGeanyIndentPrefs = record
    width : gint;
    _type : TGeanyIndentType;
    hard_tab_width : gint;
    auto_indent_mode : TGeanyAutoIndent;
    detect_type : gboolean;
    detect_width : gboolean;
  end;

  PGeanyEditorPrefs = ^TGeanyEditorPrefs;
  TGeanyEditorPrefs = record
    indentation : PGeanyIndentPrefs;
    show_white_space : gboolean;
    show_indent_guide : gboolean;
    show_line_endings : gboolean;
    long_line_type : gint;
    long_line_column : gint;
    long_line_color : Pgchar;
    show_markers_margin : gboolean;
    show_linenumber_margin : gboolean;
    show_scrollbars : gboolean;
    scroll_stop_at_last_line : gboolean;
    line_wrapping : gboolean;
    use_indicators : gboolean;
    folding : gboolean;
    unfold_all_children : gboolean;
    disable_dnd : gboolean;
    use_tab_to_indent : gboolean;
    smart_home_key : gboolean;
    newline_strip : gboolean;
    auto_complete_symbols : gboolean;
    auto_close_xml_tags : gboolean;
    complete_snippets : gboolean;
    symbolcompletion_min_chars : gint;
    symbolcompletion_max_height : gint;
    brace_match_ltgt : gboolean;
    use_gtk_word_boundaries : gboolean;
    complete_snippets_whilst_editing : gboolean;
    line_break_column : gint;
    auto_continue_multiline : gboolean;
    comment_toggle_mark : Pgchar;
    autocompletion_max_entries : guint;
    autoclose_chars : guint;
    autocomplete_doc_words : gboolean;
    completion_drops_rest_of_word : gboolean;
    color_scheme : Pgchar;
    show_virtual_space : gint;
    long_line_enabled : gboolean;
    autocompletion_update_freq : gint;
    scroll_lines_around_cursor : gint;
    ime_interaction : gint;
  end;

function editor_get_type: TGType;cdecl;external External_library name 'editor_get_type';

type
  PGeanyEditor = ^TGeanyEditor;
  PGeanyDocument = ^TGeanyDocument;
  TGeanyDocument = record
    is_valid : gboolean;
    index : gint;
    has_tags : gboolean;
    file_name : Pgchar;
    encoding : Pgchar;
    has_bom : gboolean;
    editor : PGeanyEditor;
    file_type : PGeanyFiletype;
    tm_file : PTMSourceFile;
    readonly : gboolean;
    changed : gboolean;
    real_path : Pgchar;
    id : guint;
    priv : PGeanyDocumentPrivate;
  end;

  TGeanyEditor = record
    document : PGeanyDocument;
    sci : PScintillaObject;
    line_wrapping : gboolean;
    auto_indent : gboolean;
    scroll_percent : gfloat;
    indent_type : TGeanyIndentType;
    line_breaking : gboolean;
    indent_width : gint;
  end;

function editor_get_indent_prefs(var editor:TGeanyEditor): PGeanyIndentPrefs;cdecl;external External_library name
'editor_get_indent_prefs';
function editor_create_widget(var editor:TGeanyEditor): PScintillaObject;cdecl;external External_library name
'editor_create_widget';
procedure editor_indicator_set_on_range(var editor:TGeanyEditor; indic:gint; start:gint; _end:gint);cdecl;external
External_library name 'editor_indicator_set_on_range';
procedure editor_indicator_set_on_line(var editor:TGeanyEditor; indic:gint; line:gint);cdecl;external External_library
name 'editor_indicator_set_on_line';
procedure editor_indicator_clear(var editor:TGeanyEditor; indic:gint);cdecl;external External_library name
'editor_indicator_clear';
procedure editor_set_indent_type(var editor:TGeanyEditor; _type:TGeanyIndentType);cdecl;external External_library name
'editor_set_indent_type';
procedure editor_set_indent_width(var editor:TGeanyEditor; width:gint);cdecl;external External_library name
'editor_set_indent_width';
function editor_get_word_at_pos(var editor:TGeanyEditor; pos:gint; wordchars:Pgchar): Pgchar;cdecl;external
External_library name 'editor_get_word_at_pos';
function editor_get_eol_char_name(var editor:TGeanyEditor): Pgchar;cdecl;external External_library name
'editor_get_eol_char_name';
function editor_get_eol_char_len(var editor:TGeanyEditor): gint;cdecl;external External_library name
'editor_get_eol_char_len';
function editor_get_eol_char(var editor:TGeanyEditor): Pgchar;cdecl;external External_library name 'editor_get_eol_char'
;
procedure editor_insert_text_block(var editor:TGeanyEditor; text:Pgchar; insert_pos:gint; cursor_index:gint;
                                   newline_indent_size:gint;
                                   replace_newlines:gboolean);cdecl;external External_library name
'editor_insert_text_block';
function editor_get_eol_char_mode(var editor:TGeanyEditor): gint;cdecl;external External_library name
'editor_get_eol_char_mode';
function editor_goto_pos(var editor:TGeanyEditor; pos:gint; mark:gboolean): gboolean;cdecl;external External_library
name 'editor_goto_pos';
function editor_find_snippet(var editor:TGeanyEditor; snippet_name:Pgchar): Pgchar;cdecl;external External_library name
'editor_find_snippet';
procedure editor_insert_snippet(var editor:TGeanyEditor; pos:gint; snippet:Pgchar);cdecl;external External_library name
'editor_insert_snippet';

type
  PGeanyFindFlags = ^TGeanyFindFlags;
  TGeanyFindFlags = (GEANY_FIND_MATCHCASE := 1 shl 0,GEANY_FIND_WHOLEWORD := 1 shl 1,
                     GEANY_FIND_WORDSTART := 1 shl 2,GEANY_FIND_REGEXP := 1 shl 3,
                     GEANY_FIND_MULTILINE := 1 shl 4);

  PGeanyFindSelOptions = ^TGeanyFindSelOptions;
  TGeanyFindSelOptions = (GEANY_FIND_SEL_CURRENT_WORD,GEANY_FIND_SEL_X,
                          GEANY_FIND_SEL_AGAIN);

  PGeanySearchPrefs = ^TGeanySearchPrefs;
  TGeanySearchPrefs = record
    always_wrap : gboolean;
    use_current_word : gboolean;
    use_current_file_dir : gboolean;
    hide_find_dialog : gboolean;
    replace_and_find_by_default : gboolean;
    find_selection_type : TGeanyFindSelOptions;
  end;

  PGeanyMatchInfo = ^TGeanyMatchInfo;
  TGeanyMatchInfo = record
    flags : TGeanyFindFlags;
    start : gint;
    _end : gint;
    match_text : Pgchar;
    matches : array[0..9] of record
      start : gint;
      _end : gint;
    end;
  end;

procedure search_show_find_in_files_dialog(dir:Pgchar);cdecl;external External_library name
'search_show_find_in_files_dialog';

type
  PGeanyFilePrefs = ^TGeanyFilePrefs;
  TGeanyFilePrefs = record
    default_new_encoding : gint;
    default_open_encoding : gint;
    final_new_line : gboolean;
    strip_trailing_spaces : gboolean;
    replace_tabs : gboolean;
    tab_order_ltr : gboolean;
    tab_order_beside : gboolean;
    show_tab_cross : gboolean;
    mru_length : guint;
    default_eol_character : gint;
    disk_check_timeout : gint;
    cmdline_new_files : gboolean;
    use_safe_file_saving : gboolean;
    ensure_convert_new_lines : gboolean;
    gio_unsafe_save_backup : gboolean;
    use_gio_unsafe_file_saving : gboolean;
    extract_filetype_regex : Pgchar;
    tab_close_switch_to_mru : gboolean;
    keep_edit_history_on_reload : gboolean;
    show_keep_edit_history_on_reload_msg : gboolean;
    reload_clean_doc_on_file_change : gboolean;
    save_config_on_file_change : gboolean;
  end;

function document_get_type: TGType;cdecl;external External_library name 'document_get_type';
function document_new_file(filename:Pgchar; var ft:TGeanyFiletype; text:Pgchar): PGeanyDocument;cdecl;external
External_library name 'document_new_file';
function document_get_current: PGeanyDocument;cdecl;external External_library name 'document_get_current';
function document_get_from_notebook_child(var page:TGtkWidget): PGeanyDocument;cdecl;external External_library name
'document_get_from_notebook_child';
function document_get_from_page(page_num:guint): PGeanyDocument;cdecl;external External_library name
'document_get_from_page';
function document_find_by_filename(utf8_filename:Pgchar): PGeanyDocument;cdecl;external External_library name
'document_find_by_filename';
function document_find_by_real_path(realname:Pgchar): PGeanyDocument;cdecl;external External_library name
'document_find_by_real_path';
function document_save_file(var doc:TGeanyDocument; force:gboolean): gboolean;cdecl;external External_library name
'document_save_file';
function document_open_file(locale_filename:Pgchar; readonly:gboolean; var ft:TGeanyFiletype; forced_enc:Pgchar):
                                                                                                          PGeanyDocument
;cdecl;external External_library name 'document_open_file';
procedure document_open_files(var filenames:TGSList; readonly:gboolean; var ft:TGeanyFiletype; forced_enc:Pgchar);cdecl;
external External_library name 'document_open_files';
function document_remove_page(page_num:guint): gboolean;cdecl;external External_library name 'document_remove_page';
function document_reload_force(var doc:TGeanyDocument; forced_enc:Pgchar): gboolean;cdecl;external External_library name
'document_reload_force';
procedure document_set_encoding(var doc:TGeanyDocument; new_encoding:Pgchar);cdecl;external External_library name
'document_set_encoding';
procedure document_set_text_changed(var doc:TGeanyDocument; changed:gboolean);cdecl;external External_library name
'document_set_text_changed';
procedure document_set_filetype(var doc:TGeanyDocument; var _type:TGeanyFiletype);cdecl;external External_library name
'document_set_filetype';
function document_close(var doc:TGeanyDocument): gboolean;cdecl;external External_library name 'document_close';
function document_index(idx:gint): PGeanyDocument;cdecl;external External_library name 'document_index';
function document_save_file_as(var doc:TGeanyDocument; utf8_fname:Pgchar): gboolean;cdecl;external External_library name
'document_save_file_as';
procedure document_rename_file(var doc:TGeanyDocument; new_filename:Pgchar);cdecl;external External_library name
'document_rename_file';
function document_get_status_color(var doc:TGeanyDocument): PGdkColor;cdecl;external External_library name
'document_get_status_color';
function document_get_basename_for_display(var doc:TGeanyDocument; length:gint): Pgchar;cdecl;external External_library
name 'document_get_basename_for_display';
function document_get_notebook_page(var doc:TGeanyDocument): gint;cdecl;external External_library name
'document_get_notebook_page';
function document_compare_by_display_name(a:gconstpointer; b:gconstpointer): gint;cdecl;external External_library name
'document_compare_by_display_name';
function document_compare_by_tab_order(a:gconstpointer; b:gconstpointer): gint;cdecl;external External_library name
'document_compare_by_tab_order';
function document_compare_by_tab_order_reverse(a:gconstpointer; b:gconstpointer): gint;cdecl;external External_library
name 'document_compare_by_tab_order_reverse';
function document_find_by_id(id:guint): PGeanyDocument;cdecl;external External_library name 'document_find_by_id';

type
  PGeanyBuildGroup = ^TGeanyBuildGroup;
  TGeanyBuildGroup = (GEANY_GBG_FT,GEANY_GBG_NON_FT,GEANY_GBG_EXEC,
                      GEANY_GBG_COUNT);

  PGeanyBuildSource = ^TGeanyBuildSource;
  TGeanyBuildSource = (GEANY_BCS_DEF,GEANY_BCS_FT,GEANY_BCS_HOME_FT,
                       GEANY_BCS_PREF,GEANY_BCS_PROJ_FT,GEANY_BCS_PROJ,
                       GEANY_BCS_COUNT);

  PGeanyBuildCmdEntries = ^TGeanyBuildCmdEntries;
  TGeanyBuildCmdEntries = (GEANY_BC_LABEL,GEANY_BC_COMMAND,GEANY_BC_WORKING_DIR,
                           GEANY_BC_CMDENTRIES_COUNT);

procedure build_activate_menu_item(grp:TGeanyBuildGroup; cmd:guint);cdecl;external External_library name
'build_activate_menu_item';
function build_get_current_menu_item(grp:TGeanyBuildGroup; cmd:guint; field:TGeanyBuildCmdEntries): Pgchar;cdecl;
external External_library name 'build_get_current_menu_item';
procedure build_remove_menu_item(src:TGeanyBuildSource; grp:TGeanyBuildGroup; cmd:gint);cdecl;external External_library
name 'build_remove_menu_item';
procedure build_set_menu_item(src:TGeanyBuildSource; grp:TGeanyBuildGroup; cmd:guint; field:TGeanyBuildCmdEntries; value
                              :Pgchar);cdecl;external External_library name 'build_set_menu_item';
function build_get_group_count(grp:TGeanyBuildGroup): guint;cdecl;external External_library name 'build_get_group_count'
;

type
  PGeanyEncodingIndex = ^TGeanyEncodingIndex;
  TGeanyEncodingIndex = (GEANY_ENCODING_ISO_8859_1,GEANY_ENCODING_ISO_8859_2,
                         GEANY_ENCODING_ISO_8859_3,GEANY_ENCODING_ISO_8859_4,
                         GEANY_ENCODING_ISO_8859_5,GEANY_ENCODING_ISO_8859_6,
                         GEANY_ENCODING_ISO_8859_7,GEANY_ENCODING_ISO_8859_8,
                         GEANY_ENCODING_ISO_8859_8_I,GEANY_ENCODING_ISO_8859_9,
                         GEANY_ENCODING_ISO_8859_10,GEANY_ENCODING_ISO_8859_13,
                         GEANY_ENCODING_ISO_8859_14,GEANY_ENCODING_ISO_8859_15,
                         GEANY_ENCODING_ISO_8859_16,GEANY_ENCODING_UTF_7,
                         GEANY_ENCODING_UTF_8,GEANY_ENCODING_UTF_16LE,
                         GEANY_ENCODING_UTF_16BE,GEANY_ENCODING_UCS_2LE,
                         GEANY_ENCODING_UCS_2BE,GEANY_ENCODING_UTF_32LE,
                         GEANY_ENCODING_UTF_32BE,GEANY_ENCODING_ARMSCII_8,
                         GEANY_ENCODING_BIG5,GEANY_ENCODING_BIG5_HKSCS,
                         GEANY_ENCODING_CP_866,GEANY_ENCODING_EUC_JP,
                         GEANY_ENCODING_EUC_KR,GEANY_ENCODING_EUC_TW,
                         GEANY_ENCODING_GB18030,GEANY_ENCODING_GB2312,
                         GEANY_ENCODING_GBK,GEANY_ENCODING_GEOSTD8,
                         GEANY_ENCODING_HZ,GEANY_ENCODING_IBM_850,
                         GEANY_ENCODING_IBM_852,GEANY_ENCODING_IBM_855,
                         GEANY_ENCODING_IBM_857,GEANY_ENCODING_IBM_862,
                         GEANY_ENCODING_IBM_864,GEANY_ENCODING_ISO_2022_JP,
                         GEANY_ENCODING_ISO_2022_KR,GEANY_ENCODING_ISO_IR_111,
                         GEANY_ENCODING_JOHAB,GEANY_ENCODING_KOI8_R,
                         GEANY_ENCODING_KOI8_U,GEANY_ENCODING_SHIFT_JIS,
                         GEANY_ENCODING_TCVN,GEANY_ENCODING_TIS_620,
                         GEANY_ENCODING_UHC,GEANY_ENCODING_VISCII,
                         GEANY_ENCODING_WINDOWS_1250,GEANY_ENCODING_WINDOWS_1251,
                         GEANY_ENCODING_WINDOWS_1252,GEANY_ENCODING_WINDOWS_1253,
                         GEANY_ENCODING_WINDOWS_1254,GEANY_ENCODING_WINDOWS_1255,
                         GEANY_ENCODING_WINDOWS_1256,GEANY_ENCODING_WINDOWS_1257,
                         GEANY_ENCODING_WINDOWS_1258,GEANY_ENCODING_NONE,
                         GEANY_ENCODING_CP_932,GEANY_ENCODINGS_MAX
                        );

function encodings_convert_to_utf8(buffer:Pgchar; size:gssize; used_encoding:PPgchar): Pgchar;cdecl;external
External_library name 'encodings_convert_to_utf8';
function encodings_convert_to_utf8_from_charset(buffer:Pgchar; size:gssize; charset:Pgchar; fast:gboolean): Pgchar;cdecl
;external External_library name 'encodings_convert_to_utf8_from_charset';
function encodings_get_charset_from_index(idx:gint): Pgchar;cdecl;external External_library name
'encodings_get_charset_from_index';
function dialogs_show_question(text:Pgchar; args:array of const): gboolean;cdecl;external External_library name
'dialogs_show_question';
function dialogs_show_question(text:Pgchar): gboolean;cdecl;external External_library name 'dialogs_show_question';
procedure dialogs_show_msgbox(_type:TGtkMessageType; text:Pgchar; args:array of const);cdecl;external External_library
name 'dialogs_show_msgbox';
procedure dialogs_show_msgbox(_type:TGtkMessageType; text:Pgchar);cdecl;external External_library name
'dialogs_show_msgbox';
function dialogs_show_save_as: gboolean;cdecl;external External_library name 'dialogs_show_save_as';
function dialogs_show_input_numeric(title:Pgchar; label_text:Pgchar; var value:gdouble; min:gdouble; max:gdouble;
                                    step:gdouble): gboolean;cdecl;external External_library name
'dialogs_show_input_numeric';
function dialogs_show_input(title:Pgchar; var parent:TGtkWindow; label_text:Pgchar; default_text:Pgchar): Pgchar;cdecl;
external External_library name 'dialogs_show_input';

type

  TGeanyKeyGroupCallback = function (key_id:guint): gboolean;cdecl;

  PGeanyKeyGroup = ^TGeanyKeyGroup;
  TGeanyKeyGroupFunc = function (group:PGeanyKeyGroup; key_id:guint; user_data:gpointer): gboolean;cdecl;

  TGeanyKeyCallback = procedure (key_id:guint);cdecl;

  PGeanyKeyBinding = ^TGeanyKeyBinding;
  TGeanyKeyBindingFunc = function (key:PGeanyKeyBinding; key_id:guint; user_data:gpointer): gboolean;cdecl;

  TGeanyKeyBinding = record
    key : guint;
    mods : TGdkModifierType;
    name : Pgchar;
    _label : Pgchar;
    callback : TGeanyKeyCallback;
    menu_item : PGtkWidget;
    id : guint;
    default_key : guint;
    default_mods : TGdkModifierType;
    cb_func : TGeanyKeyBindingFunc;
    cb_data : gpointer;
    cb_data_destroy : TGDestroyNotify;
  end;

  TGeanyKeyGroup = record
    name : Pgchar;
    _label : Pgchar;
    callback : TGeanyKeyGroupCallback;
    plugin : gboolean;
    key_items : PGPtrArray;
    plugin_key_count : gsize;
    plugin_keys : PGeanyKeyBinding;
    cb_func : TGeanyKeyGroupFunc;
    cb_data : gpointer;
    cb_data_destroy : TGDestroyNotify;
  end;

  TGeanyKeyGroupID = (GEANY_KEY_GROUP_FILE,GEANY_KEY_GROUP_PROJECT,
                      GEANY_KEY_GROUP_EDITOR,GEANY_KEY_GROUP_CLIPBOARD,
                      GEANY_KEY_GROUP_SELECT,GEANY_KEY_GROUP_FORMAT,
                      GEANY_KEY_GROUP_INSERT,GEANY_KEY_GROUP_SETTINGS,
                      GEANY_KEY_GROUP_SEARCH,GEANY_KEY_GROUP_GOTO,
                      GEANY_KEY_GROUP_VIEW,GEANY_KEY_GROUP_FOCUS,
                      GEANY_KEY_GROUP_NOTEBOOK,GEANY_KEY_GROUP_DOCUMENT,
                      GEANY_KEY_GROUP_BUILD,GEANY_KEY_GROUP_TOOLS,
                      GEANY_KEY_GROUP_HELP,GEANY_KEY_GROUP_COUNT
                     );

  TGeanyKeyBindingID = (GEANY_KEYS_EDITOR_TRANSPOSELINE,GEANY_KEYS_DOCUMENT_REMOVE_ERROR_INDICATORS,
                        GEANY_KEYS_FOCUS_SEARCHBAR,GEANY_KEYS_SEARCH_FIND,
                        GEANY_KEYS_FILE_SAVEALL,GEANY_KEYS_GOTO_NEXTMARKER,
                        GEANY_KEYS_NOTEBOOK_SWITCHTABLEFT,GEANY_KEYS_VIEW_ZOOMOUT,
                        GEANY_KEYS_GOTO_LINE,GEANY_KEYS_DOCUMENT_TOGGLEFOLD,
                        GEANY_KEYS_BUILD_COMPILE,GEANY_KEYS_EDITOR_SCROLLTOLINE,
                        GEANY_KEYS_DOCUMENT_UNFOLDALL,GEANY_KEYS_GOTO_MATCHINGBRACE,
                        GEANY_KEYS_SEARCH_FINDDOCUMENTUSAGE,GEANY_KEYS_CLIPBOARD_PASTE,
                        GEANY_KEYS_BUILD_MAKE,GEANY_KEYS_INSERT_ALTWHITESPACE,
                        GEANY_KEYS_EDITOR_SCROLLLINEDOWN,GEANY_KEYS_VIEW_TOGGLEALL,
                        GEANY_KEYS_VIEW_FULLSCREEN,GEANY_KEYS_GOTO_LINEEND,
                        GEANY_KEYS_EDITOR_CALLTIP,GEANY_KEYS_FILE_PRINT,
                        GEANY_KEYS_EDITOR_DUPLICATELINE,GEANY_KEYS_FOCUS_SCRIBBLE,
                        GEANY_KEYS_TOOLS_OPENCOLORCHOOSER,GEANY_KEYS_SEARCH_PREVIOUSMESSAGE,
                        GEANY_KEYS_FILE_CLOSE,GEANY_KEYS_DOCUMENT_REPLACETABS,
                        GEANY_KEYS_FILE_RELOAD,GEANY_KEYS_SEARCH_FINDNEXTSEL,
                        GEANY_KEYS_FOCUS_MESSAGES,GEANY_KEYS_BUILD_RUN,
                        GEANY_KEYS_HELP_HELP,GEANY_KEYS_SETTINGS_PLUGINPREFERENCES,
                        GEANY_KEYS_VIEW_ZOOMRESET,GEANY_KEYS_SELECT_WORD,
                        GEANY_KEYS_FORMAT_INCREASEINDENT,GEANY_KEYS_SETTINGS_PREFERENCES,
                        GEANY_KEYS_FORMAT_SENDTOCMD3,GEANY_KEYS_DOCUMENT_FOLDALL,
                        GEANY_KEYS_FORMAT_SENDTOVTE,GEANY_KEYS_PROJECT_PROPERTIES,
                        GEANY_KEYS_DOCUMENT_LINEWRAP,GEANY_KEYS_EDITOR_MACROLIST,
                        GEANY_KEYS_EDITOR_SUPPRESSSNIPPETCOMPLETION,
                        GEANY_KEYS_FOCUS_SIDEBAR_SYMBOL_LIST,GEANY_KEYS_GOTO_LINESTART,
                        GEANY_KEYS_SEARCH_FINDUSAGE,GEANY_KEYS_FILE_NEW,
                        GEANY_KEYS_EDITOR_SNIPPETNEXTCURSOR,GEANY_KEYS_NOTEBOOK_SWITCHTABRIGHT,
                        GEANY_KEYS_FILE_SAVE,GEANY_KEYS_FORMAT_INCREASEINDENTBYSPACE,
                        GEANY_KEYS_SEARCH_FINDNEXT,GEANY_KEYS_GOTO_TOGGLEMARKER,
                        GEANY_KEYS_GOTO_TAGDEFINITION,GEANY_KEYS_SEARCH_NEXTMESSAGE,
                        GEANY_KEYS_EDITOR_DELETELINETOEND,GEANY_KEYS_FORMAT_AUTOINDENT,
                        GEANY_KEYS_FILE_OPENSELECTED,GEANY_KEYS_GOTO_BACK,
                        GEANY_KEYS_INSERT_DATE,GEANY_KEYS_BUILD_PREVIOUSERROR,
                        GEANY_KEYS_GOTO_LINEENDVISUAL,GEANY_KEYS_DOCUMENT_REPLACESPACES,
                        GEANY_KEYS_FOCUS_EDITOR,GEANY_KEYS_SELECT_WORDPARTRIGHT,
                        GEANY_KEYS_VIEW_MESSAGEWINDOW,GEANY_KEYS_FOCUS_SIDEBAR_DOCUMENT_LIST,
                        GEANY_KEYS_FORMAT_REFLOWPARAGRAPH,GEANY_KEYS_EDITOR_MOVELINEUP,
                        GEANY_KEYS_NOTEBOOK_MOVETABLEFT,GEANY_KEYS_SELECT_LINE,
                        GEANY_KEYS_EDITOR_UNDO,GEANY_KEYS_EDITOR_MOVELINEDOWN,
                        GEANY_KEYS_CLIPBOARD_COPYLINE,GEANY_KEYS_BUILD_MAKEOWNTARGET,
                        GEANY_KEYS_FORMAT_SENDTOCMD2,GEANY_KEYS_SEARCH_MARKALL,
                        GEANY_KEYS_BUILD_LINK,GEANY_KEYS_FILE_CLOSEALL,
                        GEANY_KEYS_GOTO_FORWARD,GEANY_KEYS_CLIPBOARD_CUT,
                        GEANY_KEYS_NOTEBOOK_SWITCHTABLASTUSED,
                        GEANY_KEYS_NOTEBOOK_MOVETABRIGHT,GEANY_KEYS_BUILD_OPTIONS,
                        GEANY_KEYS_GOTO_TAGDECLARATION,GEANY_KEYS_FILE_OPEN,
                        GEANY_KEYS_EDITOR_COMPLETESNIPPET,GEANY_KEYS_FORMAT_UNCOMMENTLINE,
                        GEANY_KEYS_FOCUS_VTE,GEANY_KEYS_FORMAT_SENDTOCMD1,
                        GEANY_KEYS_SELECT_WORDPARTLEFT,GEANY_KEYS_VIEW_ZOOMIN,
                        GEANY_KEYS_DOCUMENT_LINEBREAK,GEANY_KEYS_EDITOR_REDO,
                        GEANY_KEYS_EDITOR_CONTEXTACTION,GEANY_KEYS_SEARCH_FINDPREVSEL,
                        GEANY_KEYS_FORMAT_DECREASEINDENTBYSPACE,
                        GEANY_KEYS_FORMAT_COMMENTLINETOGGLE,GEANY_KEYS_SELECT_ALL,
                        GEANY_KEYS_DOCUMENT_RELOADTAGLIST,GEANY_KEYS_BUILD_NEXTERROR,
                        GEANY_KEYS_NOTEBOOK_MOVETABLAST,GEANY_KEYS_SELECT_PARAGRAPH,
                        GEANY_KEYS_EDITOR_DELETELINE,GEANY_KEYS_CLIPBOARD_COPY,
                        GEANY_KEYS_VIEW_SIDEBAR,GEANY_KEYS_FILE_SAVEAS,
                        GEANY_KEYS_FORMAT_COMMENTLINE,GEANY_KEYS_GOTO_PREVWORDPART,
                        GEANY_KEYS_SEARCH_FINDPREVIOUS,GEANY_KEYS_SEARCH_REPLACE,
                        GEANY_KEYS_EDITOR_WORDPARTCOMPLETION,GEANY_KEYS_EDITOR_AUTOCOMPLETE,
                        GEANY_KEYS_FOCUS_SIDEBAR,GEANY_KEYS_FOCUS_MESSAGE_WINDOW,
                        GEANY_KEYS_NOTEBOOK_MOVETABFIRST,GEANY_KEYS_GOTO_PREVIOUSMARKER,
                        GEANY_KEYS_EDITOR_SCROLLLINEUP,GEANY_KEYS_FOCUS_COMPILER,
                        GEANY_KEYS_FORMAT_TOGGLECASE,GEANY_KEYS_CLIPBOARD_CUTLINE,
                        GEANY_KEYS_DOCUMENT_REMOVE_MARKERS,GEANY_KEYS_BUILD_MAKEOBJECT,
                        GEANY_KEYS_FORMAT_DECREASEINDENT,GEANY_KEYS_FILE_OPENLASTTAB,
                        GEANY_KEYS_SEARCH_FINDINFILES,GEANY_KEYS_GOTO_NEXTWORDPART,
                        GEANY_KEYS_INSERT_LINEAFTER,GEANY_KEYS_INSERT_LINEBEFORE,
                        GEANY_KEYS_DOCUMENT_REMOVE_MARKERS_INDICATORS,
                        GEANY_KEYS_PROJECT_OPEN,GEANY_KEYS_PROJECT_NEW,
                        GEANY_KEYS_PROJECT_CLOSE,GEANY_KEYS_FORMAT_JOINLINES,
                        GEANY_KEYS_GOTO_LINESTARTVISUAL,GEANY_KEYS_DOCUMENT_CLONE,
                        GEANY_KEYS_FILE_QUIT,GEANY_KEYS_FILE_PROPERTIES,
                        GEANY_KEYS_FORMAT_SENDTOCMD4,GEANY_KEYS_FORMAT_SENDTOCMD5,
                        GEANY_KEYS_FORMAT_SENDTOCMD6,GEANY_KEYS_FORMAT_SENDTOCMD7,
                        GEANY_KEYS_FORMAT_SENDTOCMD8,GEANY_KEYS_FORMAT_SENDTOCMD9,
                        GEANY_KEYS_EDITOR_DELETELINETOBEGINNING,
                        GEANY_KEYS_DOCUMENT_STRIPTRAILINGSPACES,
                        GEANY_KEYS_FILE_RELOAD_ALL,GEANY_KEYS_COUNT
                       );


procedure keybindings_send_command(group_id:guint; key_id:guint);cdecl;external External_library name
'keybindings_send_command';
function keybindings_set_item(var group:TGeanyKeyGroup; key_id:gsize; callback:TGeanyKeyCallback; key:guint; _mod:
                              TGdkModifierType;
                              name:Pgchar; _label:Pgchar; var menu_item:TGtkWidget): PGeanyKeyBinding;cdecl;external
External_library name 'keybindings_set_item';
function keybindings_set_item_full(var group:TGeanyKeyGroup; key_id:gsize; key:guint; _mod:TGdkModifierType; kf_name:
                                   Pgchar;
                                   _label:Pgchar; var menu_item:TGtkWidget; func:TGeanyKeyBindingFunc; pdata:gpointer;
                                   destroy_notify:TGDestroyNotify): PGeanyKeyBinding;cdecl;external External_library
name 'keybindings_set_item_full';
function keybindings_get_item(var group:TGeanyKeyGroup; key_id:gsize): PGeanyKeyBinding;cdecl;external External_library
name 'keybindings_get_item';
function keybindings_get_modifiers(mods:TGdkModifierType): TGdkModifierType;cdecl;external External_library name
'keybindings_get_modifiers';
procedure keybindings_load_keyfile;cdecl;external External_library name 'keybindings_load_keyfile';

type
  PGeanyLexerStyle = ^TGeanyLexerStyle;
  TGeanyLexerStyle = record
    foreground : gint;
    background : gint;
    bold : gboolean;
    italic : gboolean;
  end;

function highlighting_get_style(ft_id:gint; style_id:gint): PGeanyLexerStyle;cdecl;external External_library name
'highlighting_get_style';
procedure highlighting_set_styles(var sci:TScintillaObject; var ft:TGeanyFiletype);cdecl;external External_library name
'highlighting_set_styles';
function highlighting_is_string_style(lexer:gint; style:gint): gboolean;cdecl;external External_library name
'highlighting_is_string_style';
function highlighting_is_comment_style(lexer:gint; style:gint): gboolean;cdecl;external External_library name
'highlighting_is_comment_style';
function highlighting_is_code_style(lexer:gint; style:gint): gboolean;cdecl;external External_library name
'highlighting_is_code_style';

type
  TMsgColors = (COLOR_RED,COLOR_DARK_RED,COLOR_BLACK,COLOR_BLUE
               );


  PMessageWindowTabNum = ^TMessageWindowTabNum;
  TMessageWindowTabNum = (MSG_STATUS := 0,MSG_COMPILER,MSG_MESSAGE,
                          MSG_SCRATCH,MSG_VTE);

procedure msgwin_status_add(format:Pgchar; args:array of const);cdecl;external External_library name 'msgwin_status_add'
;
procedure msgwin_status_add(format:Pgchar);cdecl;external External_library name 'msgwin_status_add';
procedure msgwin_status_add_string(msg:Pgchar);cdecl;external External_library name 'msgwin_status_add_string';
procedure msgwin_compiler_add(msg_color:gint; format:Pgchar; args:array of const);cdecl;external External_library name
'msgwin_compiler_add';
procedure msgwin_compiler_add(msg_color:gint; format:Pgchar);cdecl;external External_library name 'msgwin_compiler_add';
procedure msgwin_compiler_add_string(msg_color:gint; msg:Pgchar);cdecl;external External_library name
'msgwin_compiler_add_string';
procedure msgwin_msg_add(msg_color:gint; line:gint; var doc:TGeanyDocument; format:Pgchar; args:array of const);cdecl;
external External_library name 'msgwin_msg_add';
procedure msgwin_msg_add(msg_color:gint; line:gint; var doc:TGeanyDocument; format:Pgchar);cdecl;external
External_library name 'msgwin_msg_add';
procedure msgwin_msg_add_string(msg_color:gint; line:gint; var doc:TGeanyDocument; msg:Pchar);cdecl;external
External_library name 'msgwin_msg_add_string';
procedure msgwin_clear_tab(tabnum:gint);cdecl;external External_library name 'msgwin_clear_tab';
procedure msgwin_switch_tab(tabnum:gint; show:gboolean);cdecl;external External_library name 'msgwin_switch_tab';
procedure msgwin_set_messages_dir(messages_dir:Pgchar);cdecl;external External_library name 'msgwin_set_messages_dir';
function navqueue_goto_line(var old_doc:TGeanyDocument; var new_doc:TGeanyDocument; line:gint): gboolean;cdecl;external
External_library name 'navqueue_goto_line';

type
  PGeanyPrefs = ^TGeanyPrefs;
  TGeanyPrefs = record
    load_session : gboolean;
    load_plugins : gboolean;
    save_winpos : gboolean;
    confirm_exit : gboolean;
    beep_on_errors : gboolean;
    suppress_status_messages : gboolean;
    switch_to_status : gboolean;
    auto_focus : gboolean;
    default_open_path : Pgchar;
    custom_plugin_path : Pgchar;
    save_wingeom : gboolean;
  end;

  PGeanyToolPrefs = ^TGeanyToolPrefs;
  TGeanyToolPrefs = record
    browser_cmd : Pgchar;
    term_cmd : Pgchar;
    grep_cmd : Pgchar;
    context_action_cmd : Pgchar;
  end;

procedure sci_set_text(var sci:TScintillaObject; text:Pgchar);cdecl;external External_library name 'sci_set_text';
function sci_has_selection(var sci:TScintillaObject): gboolean;cdecl;external External_library name 'sci_has_selection';
procedure sci_end_undo_action(var sci:TScintillaObject);cdecl;external External_library name 'sci_end_undo_action';
procedure sci_start_undo_action(var sci:TScintillaObject);cdecl;external External_library name 'sci_start_undo_action';
procedure sci_set_marker_at_line(var sci:TScintillaObject; line_number:gint; marker:gint);cdecl;external
External_library name 'sci_set_marker_at_line';
procedure sci_delete_marker_at_line(var sci:TScintillaObject; line_number:gint; marker:gint);cdecl;external
External_library name 'sci_delete_marker_at_line';
function sci_is_marker_set_at_line(var sci:TScintillaObject; line:gint; marker:gint): gboolean;cdecl;external
External_library name 'sci_is_marker_set_at_line';
function sci_get_col_from_position(var sci:TScintillaObject; position:gint): gint;cdecl;external External_library name
'sci_get_col_from_position';
function sci_get_line_from_position(var sci:TScintillaObject; position:gint): gint;cdecl;external External_library name
'sci_get_line_from_position';
function sci_get_position_from_line(var sci:TScintillaObject; line:gint): gint;cdecl;external External_library name
'sci_get_position_from_line';
function sci_get_current_position(var sci:TScintillaObject): gint;cdecl;external External_library name
'sci_get_current_position';
procedure sci_set_current_position(var sci:TScintillaObject; position:gint; scroll_to_caret:gboolean);cdecl;external
External_library name 'sci_set_current_position';
function sci_get_selection_start(var sci:TScintillaObject): gint;cdecl;external External_library name
'sci_get_selection_start';
function sci_get_selection_end(var sci:TScintillaObject): gint;cdecl;external External_library name
'sci_get_selection_end';
procedure sci_replace_sel(var sci:TScintillaObject; text:Pgchar);cdecl;external External_library name 'sci_replace_sel';
function sci_get_selection_mode(var sci:TScintillaObject): gint;cdecl;external External_library name
'sci_get_selection_mode';
procedure sci_set_selection_mode(var sci:TScintillaObject; mode:gint);cdecl;external External_library name
'sci_set_selection_mode';
procedure sci_set_selection_start(var sci:TScintillaObject; position:gint);cdecl;external External_library name
'sci_set_selection_start';
procedure sci_set_selection_end(var sci:TScintillaObject; position:gint);cdecl;external External_library name
'sci_set_selection_end';
function sci_get_length(var sci:TScintillaObject): gint;cdecl;external External_library name 'sci_get_length';
function sci_get_contents(var sci:TScintillaObject; buffer_len:gint): Pgchar;cdecl;external External_library name
'sci_get_contents';
function sci_get_selected_text_length(var sci:TScintillaObject): gint;cdecl;external External_library name
'sci_get_selected_text_length';
function sci_get_selection_contents(var sci:TScintillaObject): Pgchar;cdecl;external External_library name
'sci_get_selection_contents';
function sci_get_line(var sci:TScintillaObject; line_num:gint): Pgchar;cdecl;external External_library name
'sci_get_line';
function sci_get_line_length(var sci:TScintillaObject; line:gint): gint;cdecl;external External_library name
'sci_get_line_length';
function sci_get_line_count(var sci:TScintillaObject): gint;cdecl;external External_library name 'sci_get_line_count';
function sci_get_line_end_position(var sci:TScintillaObject; line:gint): gint;cdecl;external External_library name
'sci_get_line_end_position';
function sci_get_line_is_visible(var sci:TScintillaObject; line:gint): gboolean;cdecl;external External_library name
'sci_get_line_is_visible';
procedure sci_ensure_line_is_visible(var sci:TScintillaObject; line:gint);cdecl;external External_library name
'sci_ensure_line_is_visible';
function sci_get_tab_width(var sci:TScintillaObject): gint;cdecl;external External_library name 'sci_get_tab_width';
function sci_get_char_at(var sci:TScintillaObject; pos:gint): gchar;cdecl;external External_library name
'sci_get_char_at';
procedure sci_scroll_caret(var sci:TScintillaObject);cdecl;external External_library name 'sci_scroll_caret';
function sci_find_text(var sci:TScintillaObject; flags:gint; var ttf:TSci_TextToFind): gint;cdecl;external
External_library name 'sci_find_text';
procedure sci_set_font(var sci:TScintillaObject; style:gint; font:Pgchar; size:gint);cdecl;external External_library
name 'sci_set_font';
procedure sci_goto_line(var sci:TScintillaObject; line:gint; unfold:gboolean);cdecl;external External_library name
'sci_goto_line';
function sci_get_style_at(var sci:TScintillaObject; position:gint): gint;cdecl;external External_library name
'sci_get_style_at';
function sci_get_contents_range(var sci:TScintillaObject; start:gint; _end:gint): Pgchar;cdecl;external External_library
name 'sci_get_contents_range';
procedure sci_insert_text(var sci:TScintillaObject; pos:gint; text:Pgchar);cdecl;external External_library name
'sci_insert_text';
procedure sci_set_target_start(var sci:TScintillaObject; start:gint);cdecl;external External_library name
'sci_set_target_start';
procedure sci_set_target_end(var sci:TScintillaObject; _end:gint);cdecl;external External_library name
'sci_set_target_end';
function sci_replace_target(var sci:TScintillaObject; text:Pgchar; regex:gboolean): gint;cdecl;external External_library
name 'sci_replace_target';
function sci_get_lexer(var sci:TScintillaObject): gint;cdecl;external External_library name 'sci_get_lexer';
procedure sci_send_command(var sci:TScintillaObject; cmd:gint);cdecl;external External_library name 'sci_send_command';
function sci_get_current_line(var sci:TScintillaObject): gint;cdecl;external External_library name
'sci_get_current_line';
procedure sci_indicator_set(var sci:TScintillaObject; indic:gint);cdecl;external External_library name
'sci_indicator_set';
procedure sci_indicator_clear(var sci:TScintillaObject; pos:gint; len:gint);cdecl;external External_library name
'sci_indicator_clear';
procedure sci_set_line_indentation(var sci:TScintillaObject; line:gint; indent:gint);cdecl;external External_library
name 'sci_set_line_indentation';
function sci_get_line_indentation(var sci:TScintillaObject; line:gint): gint;cdecl;external External_library name
'sci_get_line_indentation';
function sci_find_matching_brace(var sci:TScintillaObject; pos:gint): gint;cdecl;external External_library name
'sci_find_matching_brace';
procedure sci_get_text(var sci:TScintillaObject; len:gint; text:Pgchar);cdecl;external External_library name
'sci_get_text';
procedure sci_get_selected_text(var sci:TScintillaObject; text:Pgchar);cdecl;external External_library name
'sci_get_selected_text';
procedure sci_get_text_range(var sci:TScintillaObject; start:gint; _end:gint; text:Pgchar);cdecl;external
External_library name 'sci_get_text_range';
function spawn_check_command(command_line:Pgchar; execute:gboolean; var error:PGError): gboolean;cdecl;external
External_library name 'spawn_check_command';
function spawn_kill_process(pid:TGPid; var error:PGError): gboolean;cdecl;external External_library name
'spawn_kill_process';
function spawn_async(working_directory:Pgchar; command_line:Pgchar; argv:PPgchar; envp:PPgchar; var child_pid:TGPid;
                     var error:PGError): gboolean;cdecl;external External_library name 'spawn_async';

const
  SPAWN_LINE_BUFFERED = $00;

type
  PSpawnFlags = ^TSpawnFlags;
  TSpawnFlags = (SPAWN_ASYNC := $00,SPAWN_SYNC := $01,
                 SPAWN_STDOUT_UNBUFFERED := $02,SPAWN_STDERR_UNBUFFERED := $04,
                 SPAWN_UNBUFFERED := $06,SPAWN_STDIN_RECURSIVE := $08,
                 SPAWN_STDOUT_RECURSIVE := $10,SPAWN_STDERR_RECURSIVE := $20,
                 SPAWN_RECURSIVE := $38);

  TSpawnReadFunc = procedure (var _string:TGString; condition:TGIOCondition; data:gpointer);cdecl;

function spawn_with_callbacks(working_directory:Pgchar; command_line:Pgchar; argv:PPgchar; envp:PPgchar; spawn_flags:
                              TSpawnFlags;
                              stdin_cb:TGIOFunc; stdin_data:gpointer; stdout_cb:TSpawnReadFunc; stdout_data:gpointer;
                              stdout_max_length:gsize;
                              stderr_cb:TSpawnReadFunc; stderr_data:gpointer; stderr_max_length:gsize; exit_cb:
                              TGChildWatchFunc; exit_data:gpointer;
                              var child_pid:TGPid; var error:PGError): gboolean;cdecl;external External_library name
'spawn_with_callbacks';

type
  PSpawnWriteData = ^TSpawnWriteData;
  TSpawnWriteData = record
    ptr : Pgchar;
    size : gsize;
  end;

function spawn_write_data(var channel:TGIOChannel; condition:TGIOCondition; var data:TSpawnWriteData): gboolean;cdecl;
external External_library name 'spawn_write_data';
function spawn_sync(working_directory:Pgchar; command_line:Pgchar; argv:PPgchar; envp:PPgchar; var stdin_data:
                    TSpawnWriteData;
                    var stdout_data:TGString; var stderr_data:TGString; var exit_status:gint; var error:PGError):
                                                                                                                gboolean
;cdecl;external External_library name 'spawn_sync';
var
  pref_groups : PGPtrArray;cvar;external;

procedure configuration_init;cdecl;external External_library name 'configuration_init';
procedure configuration_finalize;cdecl;external External_library name 'configuration_finalize';

type
  PStashGroup = ^TStashGroup;
  TStashGroup = record
      {undefined structure}
  end;


procedure configuration_add_pref_group(var group:TStashGroup; for_prefs_dialog:gboolean);cdecl;external External_library
name 'configuration_add_pref_group';
procedure configuration_add_various_pref_group(var group:TStashGroup; prefix:Pgchar);cdecl;external External_library
name 'configuration_add_various_pref_group';
procedure configuration_save;cdecl;external External_library name 'configuration_save';
function configuration_load: gboolean;cdecl;external External_library name 'configuration_load';
procedure configuration_open_files;cdecl;external External_library name 'configuration_open_files';
procedure configuration_reload_default_session;cdecl;external External_library name
'configuration_reload_default_session';
procedure configuration_save_default_session;cdecl;external External_library name 'configuration_save_default_session';
procedure configuration_clear_default_session;cdecl;external External_library name 'configuration_clear_default_session'
;
procedure configuration_load_session_files(var config:TGKeyFile; read_recent_files:gboolean);cdecl;external
External_library name 'configuration_load_session_files';
procedure configuration_save_session_files(var config:TGKeyFile);cdecl;external External_library name
'configuration_save_session_files';
procedure configuration_apply_settings;cdecl;external External_library name 'configuration_apply_settings';

type

  PStashWidgetID = ^TStashWidgetID;
  TStashWidgetID = gconstpointer;

function stash_group_get_type: TGType;cdecl;external External_library name 'stash_group_get_type';
function stash_group_new(name:Pgchar): PStashGroup;cdecl;external External_library name 'stash_group_new';
procedure stash_group_add_boolean(var group:TStashGroup; var setting:gboolean; key_name:Pgchar; default_value:gboolean);
cdecl;external External_library name 'stash_group_add_boolean';
procedure stash_group_add_integer(var group:TStashGroup; var setting:gint; key_name:Pgchar; default_value:gint);cdecl;
external External_library name 'stash_group_add_integer';
procedure stash_group_add_string(var group:TStashGroup; setting:PPgchar; key_name:Pgchar; default_value:Pgchar);cdecl;
external External_library name 'stash_group_add_string';
procedure stash_group_add_string_vector(var group:TStashGroup; setting:PPPgchar; key_name:Pgchar; default_value:PPgchar)
;cdecl;external External_library name 'stash_group_add_string_vector';
procedure stash_group_load_from_key_file(var group:TStashGroup; var keyfile:TGKeyFile);cdecl;external External_library
name 'stash_group_load_from_key_file';
procedure stash_group_save_to_key_file(var group:TStashGroup; var keyfile:TGKeyFile);cdecl;external External_library
name 'stash_group_save_to_key_file';
procedure stash_group_free(var group:TStashGroup);cdecl;external External_library name 'stash_group_free';
function stash_group_load_from_file(var group:TStashGroup; filename:Pgchar): gboolean;cdecl;external External_library
name 'stash_group_load_from_file';
function stash_group_save_to_file(var group:TStashGroup; filename:Pgchar; flags:TGKeyFileFlags): gint;cdecl;external
External_library name 'stash_group_save_to_file';
procedure stash_group_add_toggle_button(var group:TStashGroup; var setting:gboolean; key_name:Pgchar; default_value:
                                        gboolean; widget_id:TStashWidgetID);cdecl;external External_library name
'stash_group_add_toggle_button';
procedure stash_group_add_radio_buttons(var group:TStashGroup; var setting:gint; key_name:Pgchar; default_value:gint;
                                        widget_id:TStashWidgetID;
                                        enum_id:gint; args:array of const);cdecl;external External_library name
'stash_group_add_radio_buttons';
procedure stash_group_add_radio_buttons(var group:TStashGroup; var setting:gint; key_name:Pgchar; default_value:gint;
                                        widget_id:TStashWidgetID;
                                        enum_id:gint);cdecl;external External_library name
'stash_group_add_radio_buttons';
procedure stash_group_add_spin_button_integer(var group:TStashGroup; var setting:gint; key_name:Pgchar; default_value:
                                              gint; widget_id:TStashWidgetID);cdecl;external External_library name
'stash_group_add_spin_button_integer';
procedure stash_group_add_combo_box(var group:TStashGroup; var setting:gint; key_name:Pgchar; default_value:gint;
                                    widget_id:TStashWidgetID);cdecl;external External_library name
'stash_group_add_combo_box';
procedure stash_group_add_combo_box_entry(var group:TStashGroup; setting:PPgchar; key_name:Pgchar; default_value:Pgchar;
                                          widget_id:TStashWidgetID);cdecl;external External_library name
'stash_group_add_combo_box_entry';
procedure stash_group_add_entry(var group:TStashGroup; setting:PPgchar; key_name:Pgchar; default_value:Pgchar; widget_id
                                :TStashWidgetID);cdecl;external External_library name 'stash_group_add_entry';
procedure stash_group_add_widget_property(var group:TStashGroup; setting:gpointer; key_name:Pgchar; default_value:
                                          gpointer; widget_id:TStashWidgetID;
                                          property_name:Pgchar; _type:TGType);cdecl;external External_library name
'stash_group_add_widget_property';
procedure stash_group_display(var group:TStashGroup; var owner:TGtkWidget);cdecl;external External_library name
'stash_group_display';
procedure stash_group_update(var group:TStashGroup; var owner:TGtkWidget);cdecl;external External_library name
'stash_group_update';
procedure stash_group_free_settings(var group:TStashGroup);cdecl;external External_library name
'stash_group_free_settings';
function symbols_get_context_separator(ft_id:gint): Pgchar;cdecl;external External_library name
'symbols_get_context_separator';

type
  PGeanyTemplatePrefs = ^TGeanyTemplatePrefs;
  TGeanyTemplatePrefs = record
    developer : Pgchar;
    company : Pgchar;
    mail : Pgchar;
    initials : Pgchar;
    version : Pgchar;
    year_format : Pgchar;
    date_format : Pgchar;
    datetime_format : Pgchar;
  end;

function templates_get_template_fileheader(filetype_idx:gint; fname:Pgchar): Pgchar;cdecl;external External_library name
'templates_get_template_fileheader';

type
  PGeanyToolbarPrefs = ^TGeanyToolbarPrefs;
  TGeanyToolbarPrefs = record
    visible : gboolean;
    icon_size : TGtkIconSize;
    icon_style : TGtkToolbarStyle;
    use_gtk_default_style : gboolean;
    use_gtk_default_icon : gboolean;
    append_to_menu : gboolean;
  end;

  PGeanyInterfacePrefs = ^TGeanyInterfacePrefs;
  TGeanyInterfacePrefs = record
    sidebar_symbol_visible : gboolean;
    sidebar_openfiles_visible : gboolean;
    editor_font : Pgchar;
    tagbar_font : Pgchar;
    msgwin_font : Pgchar;
    show_notebook_tabs : gboolean;
    tab_pos_editor : gint;
    tab_pos_msgwin : gint;
    tab_pos_sidebar : gint;
    statusbar_visible : gboolean;
    show_symbol_list_expanders : gboolean;
    notebook_double_click_hides_widgets : gboolean;
    highlighting_invert_all : gboolean;
    sidebar_pos : gint;
    msgwin_status_visible : gboolean;
    msgwin_compiler_visible : gboolean;
    msgwin_messages_visible : gboolean;
    msgwin_scribble_visible : gboolean;
    use_native_windows_dialogs : gboolean;
    compiler_tab_autoscroll : gboolean;
    msgwin_orientation : gint;
    symbols_sort_mode : gint;
  end;

  PGeanyMainWidgets = ^TGeanyMainWidgets;
  TGeanyMainWidgets = record
    window : PGtkWidget;
    toolbar : PGtkWidget;
    sidebar_notebook : PGtkWidget;
    notebook : PGtkWidget;
    editor_menu : PGtkWidget;
    tools_menu : PGtkWidget;
    progressbar : PGtkWidget;
    message_window_notebook : PGtkWidget;
    project_menu : PGtkWidget;
  end;

function ui_dialog_vbox_new(var dialog:TGtkDialog): PGtkWidget;cdecl;external External_library name 'ui_dialog_vbox_new'
;
procedure ui_set_statusbar(log:gboolean; format:Pgchar; args:array of const);cdecl;external External_library name
'ui_set_statusbar';
procedure ui_set_statusbar(log:gboolean; format:Pgchar);cdecl;external External_library name 'ui_set_statusbar';
procedure ui_table_add_row(var table:TGtkTable; row:gint; args:array of const);cdecl;external External_library name
'ui_table_add_row';
procedure ui_table_add_row(var table:TGtkTable; row:gint);cdecl;external External_library name 'ui_table_add_row';
function ui_path_box_new(title:Pgchar; action:TGtkFileChooserAction; var entry:TGtkEntry): PGtkWidget;cdecl;external
External_library name 'ui_path_box_new';
function ui_button_new_with_image(stock_id:Pgchar; text:Pgchar): PGtkWidget;cdecl;external External_library name
'ui_button_new_with_image';
procedure ui_add_document_sensitive(var widget:TGtkWidget);cdecl;external External_library name
'ui_add_document_sensitive';
function ui_image_menu_item_new(stock_id:Pgchar; _label:Pgchar): PGtkWidget;cdecl;external External_library name
'ui_image_menu_item_new';
function ui_lookup_widget(var widget:TGtkWidget; widget_name:Pgchar): PGtkWidget;cdecl;external External_library name
'ui_lookup_widget';
procedure ui_progress_bar_start(text:Pgchar);cdecl;external External_library name 'ui_progress_bar_start';
procedure ui_progress_bar_stop;cdecl;external External_library name 'ui_progress_bar_stop';
procedure ui_entry_add_clear_icon(var entry:TGtkEntry);cdecl;external External_library name 'ui_entry_add_clear_icon';
procedure ui_menu_add_document_items(var menu:TGtkMenu; var active:TGeanyDocument; callback:TGCallback);cdecl;external
External_library name 'ui_menu_add_document_items';
procedure ui_menu_add_document_items_sorted(var menu:TGtkMenu; var active:TGeanyDocument; callback:TGCallback; sort_func
                                            :TGCompareFunc);cdecl;external External_library name
'ui_menu_add_document_items_sorted';
procedure ui_widget_modify_font_from_string(var wid:TGtkWidget; str:Pgchar);cdecl;external External_library name
'ui_widget_modify_font_from_string';
function ui_is_keyval_enter_or_return(keyval:guint): gboolean;cdecl;external External_library name
'ui_is_keyval_enter_or_return';
function ui_get_gtk_settings_integer(property_name:Pgchar; default_value:gint): gint;cdecl;external External_library
name 'ui_get_gtk_settings_integer';
procedure ui_combo_box_add_to_history(var combo_entry:TGtkComboBoxText; text:Pgchar; history_len:gint);cdecl;external
External_library name 'ui_combo_box_add_to_history';
function ui_lookup_stock_label(stock_id:Pgchar): Pgchar;cdecl;external External_library name 'ui_lookup_stock_label';
procedure ui_tree_view_set_tooltip_text_column(var tree_view:TGtkTreeView; column:gint);cdecl;external External_library
name 'ui_tree_view_set_tooltip_text_column';
function ui_frame_new_with_alignment(label_text:Pgchar; var alignment:PGtkWidget): PGtkWidget;cdecl;external
External_library name 'ui_frame_new_with_alignment';
procedure ui_widget_set_tooltip_text(var widget:TGtkWidget; text:Pgchar);cdecl;external External_library name
'ui_widget_set_tooltip_text';
function utils_str_equal(a:Pgchar; b:Pgchar): gboolean;cdecl;external External_library name 'utils_str_equal';
function utils_string_replace_all(var haystack:TGString; needle:Pgchar; replace:Pgchar): guint;cdecl;external
External_library name 'utils_string_replace_all';
function utils_get_file_list(path:Pgchar; var length:guint; var error:PGError): PGSList;cdecl;external External_library
name 'utils_get_file_list';
function utils_get_file_list_full(path:Pgchar; full_path:gboolean; sort:gboolean; var error:PGError): PGSList;cdecl;
external External_library name 'utils_get_file_list_full';
function utils_write_file(filename:Pgchar; text:Pgchar): gint;cdecl;external External_library name 'utils_write_file';
function utils_get_locale_from_utf8(utf8_text:Pgchar): Pgchar;cdecl;external External_library name
'utils_get_locale_from_utf8';
function utils_get_utf8_from_locale(locale_text:Pgchar): Pgchar;cdecl;external External_library name
'utils_get_utf8_from_locale';
function utils_remove_ext_from_filename(filename:Pgchar): Pgchar;cdecl;external External_library name
'utils_remove_ext_from_filename';
function utils_mkdir(path:Pgchar; create_parent_dirs:gboolean): gint;cdecl;external External_library name 'utils_mkdir';
function utils_get_setting_boolean(var config:TGKeyFile; section:Pgchar; key:Pgchar; default_value:gboolean): gboolean;
cdecl;external External_library name 'utils_get_setting_boolean';
function utils_get_setting_integer(var config:TGKeyFile; section:Pgchar; key:Pgchar; default_value:gint): gint;cdecl;
external External_library name 'utils_get_setting_integer';
function utils_get_setting_string(var config:TGKeyFile; section:Pgchar; key:Pgchar; default_value:Pgchar): Pgchar;cdecl;
external External_library name 'utils_get_setting_string';
function utils_spawn_sync(dir:Pgchar; argv:PPgchar; env:PPgchar; flags:TGSpawnFlags; child_setup:TGSpawnChildSetupFunc;
                          user_data:gpointer; std_out:PPgchar; std_err:PPgchar; var exit_status:gint; var error:PGError)
: gboolean;cdecl;external External_library name 'utils_spawn_sync';
function utils_spawn_async(dir:Pgchar; argv:PPgchar; env:PPgchar; flags:TGSpawnFlags; child_setup:TGSpawnChildSetupFunc;
                           user_data:gpointer; var child_pid:TGPid; var error:PGError): gboolean;cdecl;external
External_library name 'utils_spawn_async';
function utils_str_casecmp(s1:Pgchar; s2:Pgchar): gint;cdecl;external External_library name 'utils_str_casecmp';
function utils_get_date_time(format:Pgchar; var time_to_use:time_t): Pgchar;cdecl;external External_library name
'utils_get_date_time';
procedure utils_open_browser(uri:Pgchar);cdecl;external External_library name 'utils_open_browser';
function utils_string_replace_first(var haystack:TGString; needle:Pgchar; replace:Pgchar): guint;cdecl;external
External_library name 'utils_string_replace_first';
function utils_str_middle_truncate(_string:Pgchar; truncate_length:guint): Pgchar;cdecl;external External_library name
'utils_str_middle_truncate';
function utils_str_remove_chars(_string:Pgchar; chars:Pgchar): Pgchar;cdecl;external External_library name
'utils_str_remove_chars';
function utils_copy_environment(exclude_vars:PPgchar; first_varname:Pgchar; args:array of const): Pgchar;cdecl;external
External_library name 'utils_copy_environment';
function utils_copy_environment(exclude_vars:PPgchar; first_varname:Pgchar): Pgchar;cdecl;external External_library name
'utils_copy_environment';
function utils_find_open_xml_tag(sel:Pgchar; size:gint): Pgchar;cdecl;external External_library name
'utils_find_open_xml_tag';
function utils_find_open_xml_tag_pos(sel:Pgchar; size:gint): Pgchar;cdecl;external External_library name
'utils_find_open_xml_tag_pos';
function utils_get_real_path(file_name:Pgchar): Pgchar;cdecl;external External_library name 'utils_get_real_path';
function utils_strv_shorten_file_list(file_names:PPgchar; file_names_len:gssize): Pgchar;cdecl;external External_library
name 'utils_strv_shorten_file_list';
procedure main_reload_configuration;cdecl;external External_library name 'main_reload_configuration';
procedure main_locale_init(locale_dir:Pgchar; gettext_package:Pgchar);cdecl;external External_library name
'main_locale_init';
function main_is_realized: gboolean;cdecl;external External_library name 'main_is_realized';

type
  PPluginInfo = ^TPluginInfo;
  TPluginInfo = record
    name : Pgchar;
    description : Pgchar;
    version : Pgchar;
    author : Pgchar;
  end;

  PPluginCallback = ^TPluginCallback;
  TPluginCallback = record
    signal_name : Pgchar;
    callback : TGCallback;
    after : gboolean;
    user_data : gpointer;
  end;

  PGeanyData = ^TGeanyData;
  TGeanyData = record
    app : PGeanyApp;
    main_widgets : PGeanyMainWidgets;
    documents_array : PGPtrArray;
    filetypes_array : PGPtrArray;
    prefs : PGeanyPrefs;
    interface_prefs : PGeanyInterfacePrefs;
    toolbar_prefs : PGeanyToolbarPrefs;
    editor_prefs : PGeanyEditorPrefs;
    file_prefs : PGeanyFilePrefs;
    search_prefs : PGeanySearchPrefs;
    tool_prefs : PGeanyToolPrefs;
    template_prefs : PGeanyTemplatePrefs;
    _compat : Pgpointer;
    filetypes_by_title : PGSList;
    _object : PGObject;
  end;

  PGeanyPluginFuncs = ^TGeanyPluginFuncs;
  PGeanyProxyFuncs = ^TGeanyProxyFuncs;
  PGeanyPlugin = ^TGeanyPlugin;
  TGeanyPlugin = record
    info : PPluginInfo;
    geany_data : PGeanyData;
    funcs : PGeanyPluginFuncs;
    proxy_funcs : PGeanyProxyFuncs;
    priv : PGeanyPluginPrivate;
  end;

  TGeanyPluginFuncs = record
    callbacks : PPluginCallback;
    init : function (var plugin:TGeanyPlugin; pdata:gpointer): gboolean;cdecl;
    configure : function (var plugin:TGeanyPlugin; var dialog:TGtkDialog; pdata:gpointer): PGtkWidget;cdecl;
    help : procedure (var plugin:TGeanyPlugin; pdata:gpointer);cdecl;
    cleanup : procedure (var plugin:TGeanyPlugin; pdata:gpointer);cdecl;
  end;

  TGeanyProxyFuncs = record
    probe : function (var proxy:TGeanyPlugin; filename:Pgchar; pdata:gpointer): gint;cdecl;
    load : function (var proxy:TGeanyPlugin; var subplugin:TGeanyPlugin; filename:Pgchar; pdata:gpointer): gpointer;
    cdecl;
    unload : procedure (var proxy:TGeanyPlugin; var subplugin:TGeanyPlugin; load_data:gpointer; pdata:gpointer);cdecl;
  end;

function plugin_version_check(abi_ver:gint): gint;cdecl;external External_library name 'plugin_version_check';
procedure plugin_set_info(var info:TPluginInfo);cdecl;external External_library name 'plugin_set_info';
procedure plugin_init(var data:TGeanyData);cdecl;external External_library name 'plugin_init';
function plugin_configure(var dialog:TGtkDialog): PGtkWidget;cdecl;external External_library name 'plugin_configure';
procedure plugin_configure_single(var parent:TGtkWidget);cdecl;external External_library name 'plugin_configure_single';
procedure plugin_help;cdecl;external External_library name 'plugin_help';
procedure plugin_cleanup;cdecl;external External_library name 'plugin_cleanup';
procedure geany_load_module(var plugin:TGeanyPlugin);cdecl;external External_library name 'geany_load_module';



function geany_plugin_register(var plugin:TGeanyPlugin; api_version:gint; min_api_version:gint; abi_version:gint):
                                                                                                                gboolean
;cdecl;external External_library name 'geany_plugin_register';
function geany_plugin_register_full(var plugin:TGeanyPlugin; api_version:gint; min_api_version:gint; abi_version:gint;
                                    data:gpointer;
                                    free_func:TGDestroyNotify): gboolean;cdecl;external External_library name
'geany_plugin_register_full';
function geany_plugin_get_data(var plugin:TGeanyPlugin): gpointer;cdecl;external External_library name
'geany_plugin_get_data';
procedure geany_plugin_set_data(var plugin:TGeanyPlugin; data:gpointer; free_func:TGDestroyNotify);cdecl;external
External_library name 'geany_plugin_set_data';

type
  PGeanyProxyProbeResults = ^TGeanyProxyProbeResults;
  TGeanyProxyProbeResults = (GEANY_PROXY_IGNORE,GEANY_PROXY_MATCH,GEANY_PROXY_RELATED := GEANY_PROXY_MATCH or $100
                            );


function geany_plugin_register_proxy(var plugin:TGeanyPlugin; extensions:PPgchar): gint;cdecl;external External_library
name 'geany_plugin_register_proxy';

type
  PGeanyKeyGroupInfo = ^TGeanyKeyGroupInfo;
  TGeanyKeyGroupInfo = record
    name : Pgchar;
    count : gsize;
  end;

  PPluginFlags = ^TPluginFlags;
  TPluginFlags = (PLUGIN_IS_DOCUMENT_SENSITIVE := 1 shl 0);

  PPluginFields = ^TPluginFields;
  TPluginFields = record
    flags : TPluginFlags;
    menu_item : PGtkWidget;
  end;

function geany_api_version: gint;cdecl;external External_library name 'geany_api_version';
procedure plugin_add_toolbar_item(var plugin:TGeanyPlugin; var item:TGtkToolItem);cdecl;external External_library name
'plugin_add_toolbar_item';
procedure plugin_module_make_resident(var plugin:TGeanyPlugin);cdecl;external External_library name
'plugin_module_make_resident';
procedure plugin_signal_connect(var plugin:TGeanyPlugin; var _object:TGObject; signal_name:Pgchar; after:gboolean;
                                callback:TGCallback;
                                user_data:gpointer);cdecl;external External_library name 'plugin_signal_connect';
function plugin_timeout_add(var plugin:TGeanyPlugin; interval:guint; _function:TGSourceFunc; data:gpointer): guint;cdecl
;external External_library name 'plugin_timeout_add';
function plugin_timeout_add_seconds(var plugin:TGeanyPlugin; interval:guint; _function:TGSourceFunc; data:gpointer):
                                                                                                                   guint
;cdecl;external External_library name 'plugin_timeout_add_seconds';
function plugin_idle_add(var plugin:TGeanyPlugin; _function:TGSourceFunc; data:gpointer): guint;cdecl;external
External_library name 'plugin_idle_add';

function plugin_set_key_group_full(var plugin:TGeanyPlugin; section_name:Pgchar; count:gsize; cb:TGeanyKeyGroupFunc;
                                   pdata:gpointer;
                                   destroy_notify:TGDestroyNotify): PGeanyKeyGroup;cdecl;external External_library name
'plugin_set_key_group_full';
procedure plugin_show_configure(var plugin:TGeanyPlugin);cdecl;external External_library name 'plugin_show_configure';
procedure plugin_builder_connect_signals(var plugin:TGeanyPlugin; var builder:TGtkBuilder; user_data:gpointer);cdecl;
external External_library name 'plugin_builder_connect_signals';
function plugin_get_document_data(var plugin:TGeanyPlugin; var doc:TGeanyDocument; key:Pgchar): gpointer;cdecl;external
External_library name 'plugin_get_document_data';
procedure plugin_set_document_data(var plugin:TGeanyPlugin; var doc:TGeanyDocument; key:Pgchar; data:gpointer);cdecl;
external External_library name 'plugin_set_document_data';
procedure plugin_set_document_data_full(var plugin:TGeanyPlugin; var doc:TGeanyDocument; key:Pgchar; data:gpointer;
                                        free_func:TGDestroyNotify);cdecl;external External_library name
'plugin_set_document_data_full';