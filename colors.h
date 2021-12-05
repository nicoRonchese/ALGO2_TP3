#ifndef __COLORS__
#define __COLORS__

/* ╔═════════════════════════════════════════════════════════════════════════════════╗
   ║ Dear User,                                                                      ║
   ║                                                                                 ║
   ║ In this header file you'll find macros to add color to your terminal outputs in ║ 
   ║ C or C++.                                                                       ║
   ║ To learn how to use it please see USAGE.                                        ║
   ║                                                                                 ║
   ║ It was intended to have all 256 colors, but since some were repetitive and      ║
   ║ others were hardly ever used I have decided to include only 207 of them.        ║  
   ║                                                                                 ║
   ║ These colors are grouped by shade. If you feel the grouping is not ideal feel   ║
   ║ free to edit to your liking.                                                    ║
   ║                                                                                 ║
   ║ I hope I've been helpful. Good luck!                                            ║
   ║                                                                           Rocío ║
   ╚═════════════════════════════════════════════════════════════════════════════════╝
 */


/* ╔═════════════════════════════════════════════════════════════════════════════════╗
   ║                                      USAGE                                      ║
   ║    To add color to your output texts follow the example:                        ║
   ║                                                                                 ║
   ║       cout << BGND_DARK_RED_52 << "Sample text" << END_COLOR << endl;           ║
   ║                                                                                 ║
   ║    Add color before text and end it with END_COLOR when you want to             ║
   ║    change back to default text color.                                           ║
   ║                                                                                 ║
   ║    Text and Background color can be combined by adding one of each macro        ║
   ║    before the text. The order is irrelevant. Ex:                                ║
   ║                                                                                 ║
   ║   cout << BGND_AQUA_35 << BGND_BLACK_16 << "Sample text" << END_COLOR << endl;  ║
   ║                                                                                 ║
   ╚═════════════════════════════════════════════════════════════════════════════════╝
 */

//   End color scape sequence
#define END_COLOR "\033[0m"

//   Formats    --To switch off use END_COLOR. Usage is the same as colors.
#define TXT_BOLD "\033[1m"
//Supported in Gnome terminal (not sure about other terminals)
#define TXT_ITALIC "\033[3m"           
#define TXT_UNDERLINE "\033[4m"        
#define TXT_STRIKE_THROUGH "\033[9m"   


//          Background Color
//Red
#define BGND_DARK_RED_52 "\033[48;5;52m"
#define BGND_DARK_RED_88 "\033[48;5;88m"
#define BGND_DARK_RED_1 "\033[48;5;1m"

#define BGND_RED_124 "\033[48;5;124m"
#define BGND_RED_160 "\033[48;5;160m"
#define BGND_RED_196 "\033[48;5;196m"

#define BGND_LIGHT_RED_9 "\033[48;5;9m"

//Green
#define BGND_DARK_GREEN_22 "\033[48;5;22m"
#define BGND_DARK_GREEN_28 "\033[48;5;28m"

#define BGND_GREEN_2 "\033[48;5;2m"
#define BGND_GREEN_10 "\033[48;5;10m"
#define BGND_GREEN_34 "\033[48;5;34m"
#define BGND_GREEN_40 "\033[48;5;40m"
#define BGND_GREEN_64 "\033[48;5;64m"
#define BGND_GREEN_70 "\033[48;5;70m"
#define BGND_GREEN_76 "\033[48;5;76m"
#define BGND_GREEN_112 "\033[48;5;112m"
#define BGND_GREEN_118 "\033[48;5;118m"

#define BGND_LIGHT_GREEN_46 "\033[48;5;46m"
#define BGND_LIGHT_GREEN_47 "\033[48;5;47m"
#define BGND_LIGHT_GREEN_77 "\033[48;5;77m"
#define BGND_LIGHT_GREEN_82 "\033[48;5;82m"
#define BGND_LIGHT_GREEN_119 "\033[48;5;119m"

//Blue
#define BGND_DARK_BLUE_17 "\033[48;5;17m"
#define BGND_DARK_BLUE_18 "\033[48;5;18m"

#define BGND_BLUE_4 "\033[48;5;4m"
#define BGND_BLUE_12 "\033[48;5;12m"
#define BGND_BLUE_19 "\033[48;5;19m"
#define BGND_BLUE_20 "\033[48;5;20m"
#define BGND_BLUE_21 "\033[48;5;21m"
#define BGND_BLUE_25 "\033[48;5;25m"
#define BGND_BLUE_26 "\033[48;5;26m"
#define BGND_BLUE_27 "\033[48;5;27m"
#define BGND_BLUE_56 "\033[48;5;56m"
#define BGND_BLUE_57 "\033[48;5;57m"
#define BGND_BLUE_63 "\033[48;5;63m"

#define BGND_LIGHT_BLUE_6 "\033[48;5;6m"
#define BGND_LIGHT_BLUE_14 "\033[48;5;14m"
#define BGND_LIGHT_BLUE_32 "\033[48;5;32m"
#define BGND_LIGHT_BLUE_33 "\033[48;5;33m"
#define BGND_LIGHT_BLUE_38 "\033[48;5;38m"
#define BGND_LIGHT_BLUE_39 "\033[48;5;39m"
#define BGND_LIGHT_BLUE_44 "\033[48;5;44m"
#define BGND_LIGHT_BLUE_45 "\033[48;5;45m"
#define BGND_LIGHT_BLUE_50 "\033[48;5;50m"
#define BGND_LIGHT_BLUE_51 "\033[48;5;51m"
#define BGND_LIGHT_BLUE_68 "\033[48;5;68m"
#define BGND_LIGHT_BLUE_69 "\033[48;5;69m"
#define BGND_LIGHT_BLUE_74 "\033[48;5;74m"
#define BGND_LIGHT_BLUE_75 "\033[48;5;75m"
#define BGND_LIGHT_BLUE_80 "\033[48;5;80m"
#define BGND_LIGHT_BLUE_81 "\033[48;5;81m"
#define BGND_LIGHT_BLUE_86 "\033[48;5;86m"
#define BGND_LIGHT_BLUE_87 "\033[48;5;87m"

//Yellow
#define BGND_DARK_YELLOW_3 "\033[48;5;3m"
#define BGND_DARK_YELLOW_58 "\033[48;5;58m"
#define BGND_DARK_YELLOW_100 "\033[48;5;100m"
#define BGND_DARK_YELLOW_106 "\033[48;5;106m"
#define BGND_DARK_YELLOW_142 "\033[48;5;142m"

#define BGND_YELLOW_148 "\033[48;5;148m"
#define BGND_YELLOW_154 "\033[48;5;154m"
#define BGND_YELLOW_184 "\033[48;5;184m"
#define BGND_YELLOW_190 "\033[48;5;190m"
#define BGND_YELLOW_220 "\033[48;5;220m"
#define BGND_YELLOW_226 "\033[48;5;226m"

#define BGND_LIGHT_YELLOW_149 "\033[48;5;149m"
#define BGND_LIGHT_YELLOW_150 "\033[48;5;150m"
#define BGND_LIGHT_YELLOW_155 "\033[48;5;155m"
#define BGND_LIGHT_YELLOW_156 "\033[48;5;156m"
#define BGND_LIGHT_YELLOW_185 "\033[48;5;185m"
#define BGND_LIGHT_YELLOW_186 "\033[48;5;186m"
#define BGND_LIGHT_YELLOW_191 "\033[48;5;191m"
#define BGND_LIGHT_YELLOW_192 "\033[48;5;192m"
#define BGND_LIGHT_YELLOW_221 "\033[48;5;221m"
#define BGND_LIGHT_YELLOW_222 "\033[48;5;222m"
#define BGND_LIGHT_YELLOW_227 "\033[48;5;227m"
#define BGND_LIGHT_YELLOW_228 "\033[48;5;228m"

//Orange
#define BGND_ORANGE_130 "\033[48;5;130m"
#define BGND_ORANGE_166 "\033[48;5;166m"
#define BGND_ORANGE_172 "\033[48;5;172m"
#define BGND_ORANGE_202 "\033[48;5;202m"
#define BGND_ORANGE_208 "\033[48;5;130m"
#define BGND_ORANGE_214 "\033[48;5;214m"

//Brown
#define BGND_BROWN_94 "\033[48;5;94m"
#define BGND_BROWN_136 "\033[48;5;136m"
#define BGND_BROWN_137 "\033[48;5;137m"

//Aqua
#define BGND_DARK_AQUA_23 "\033[48;5;23m"
#define BGND_DARK_AQUA_24 "\033[48;5;24m"
#define BGND_DARK_AQUA_29 "\033[48;5;29m"
#define BGND_DARK_AQUA_30 "\033[48;5;30m"
#define BGND_DARK_AQUA_31 "\033[48;5;31m"
#define BGND_DARK_AQUA_65 "\033[48;5;65m"
#define BGND_DARK_AQUA_66 "\033[48;5;66m"
#define BGND_DARK_AQUA_67 "\033[48;5;67m"

#define BGND_AQUA_35 "\033[48;5;35m"
#define BGND_AQUA_36 "\033[48;5;36m"
#define BGND_AQUA_37 "\033[48;5;37m"
#define BGND_AQUA_71 "\033[48;5;71m"
#define BGND_AQUA_78 "\033[48;5;78m"
#define BGND_AQUA_83 "\033[48;5;83m"
#define BGND_AQUA_113 "\033[48;5;113m"
#define BGND_AQUA_119 "\033[48;5;119m"

#define BGND_LIGHT_AQUA_41 "\033[48;5;41m"
#define BGND_LIGHT_AQUA_42 "\033[48;5;42m"
#define BGND_LIGHT_AQUA_43 "\033[48;5;43m"
#define BGND_LIGHT_AQUA_48 "\033[48;5;48m"
#define BGND_LIGHT_AQUA_49 "\033[48;5;49m"
#define BGND_LIGHT_AQUA_72 "\033[48;5;72m"
#define BGND_LIGHT_AQUA_73 "\033[48;5;73m"
#define BGND_LIGHT_AQUA_79 "\033[48;5;79m"
#define BGND_LIGHT_AQUA_84 "\033[48;5;84m"
#define BGND_LIGHT_AQUA_85 "\033[48;5;85m"
#define BGND_LIGHT_AQUA_114 "\033[48;5;114m"
#define BGND_LIGHT_AQUA_120 "\033[48;5;120m"
#define BGND_LIGHT_AQUA_121 "\033[48;5;121m"
#define BGND_LIGHT_AQUA_122 "\033[48;5;122m"
#define BGND_LIGHT_AQUA_123 "\033[48;5;123m"

//Purple
#define BGND_DARK_PURPLE_53 "\033[48;5;53m"
#define BGND_DARK_PURPLE_54 "\033[48;5;54m"
#define BGND_DARK_PURPLE_55 "\033[48;5;55m"
#define BGND_DARK_PURPLE_89 "\033[48;5;89m"
#define BGND_DARK_PURPLE_90 "\033[48;5;90m"
#define BGND_DARK_PURPLE_96 "\033[48;5;96m"
#define BGND_DARK_PURPLE_125 "\033[48;5;125m"
#define BGND_DARK_PURPLE_126 "\033[48;5;126m"
#define BGND_DARK_PURPLE_127 "\033[48;5;127m"

#define BGND_PURPLE_5 "\033[48;5;5m"
#define BGND_PURPLE_13 "\033[48;5;13m"
#define BGND_PURPLE_91 "\033[48;5;91m"
#define BGND_PURPLE_92 "\033[48;5;92m"
#define BGND_PURPLE_93 "\033[48;5;93m"
#define BGND_PURPLE_97 "\033[48;5;97m"
#define BGND_PURPLE_98 "\033[48;5;98m"
#define BGND_PURPLE_99 "\033[48;5;99m"
#define BGND_PURPLE_128 "\033[48;5;128m"
#define BGND_PURPLE_129 "\033[48;5;129m"

#define BGND_LIGHT_PURPLE_104 "\033[48;5;104m"
#define BGND_LIGHT_PURPLE_105 "\033[48;5;105m"
#define BGND_LIGHT_PURPLE_133 "\033[48;5;133m"
#define BGND_LIGHT_PURPLE_134 "\033[48;5;134m"
#define BGND_LIGHT_PURPLE_135 "\033[48;5;135m"
#define BGND_LIGHT_PURPLE_140 "\033[48;5;140m"
#define BGND_LIGHT_PURPLE_141 "\033[48;5;141m"
#define BGND_LIGHT_PURPLE_164 "\033[48;5;164m"
#define BGND_LIGHT_PURPLE_165 "\033[48;5;165m"
#define BGND_LIGHT_PURPLE_170 "\033[48;5;170m"
#define BGND_LIGHT_PURPLE_171 "\033[48;5;171m"
#define BGND_LIGHT_PURPLE_176 "\033[48;5;176m"
#define BGND_LIGHT_PURPLE_177 "\033[48;5;177m"

//Pink
#define BGND_DARK_PINK_131 "\033[48;5;131m"
#define BGND_DARK_PINK_132 "\033[48;5;132m"
#define BGND_DARK_PINK_174 "\033[48;5;174m"

#define BGND_PINK_161 "\033[48;5;161m"
#define BGND_PINK_162 "\033[48;5;162m"
#define BGND_PINK_163 "\033[48;5;163m"
#define BGND_PINK_197 "\033[48;5;197m"
#define BGND_PINK_198 "\033[48;5;198m"
#define BGND_PINK_199 "\033[48;5;199m"
#define BGND_PINK_200 "\033[48;5;200m"
#define BGND_PINK_201 "\033[48;5;201m"

#define BGND_LIGHT_PINK_167 "\033[48;5;167m"
#define BGND_LIGHT_PINK_168 "\033[48;5;168m"
#define BGND_LIGHT_PINK_169 "\033[48;5;169m"
#define BGND_LIGHT_PINK_203 "\033[48;5;203m"
#define BGND_LIGHT_PINK_204 "\033[48;5;204m"
#define BGND_LIGHT_PINK_205 "\033[48;5;205m"
#define BGND_LIGHT_PINK_206 "\033[48;5;206m"
#define BGND_LIGHT_PINK_207 "\033[48;5;207m"
#define BGND_LIGHT_PINK_209 "\033[48;5;209m"
#define BGND_LIGHT_PINK_210 "\033[48;5;210m"
#define BGND_LIGHT_PINK_211 "\033[48;5;211m"
#define BGND_LIGHT_PINK_212 "\033[48;5;212m"
#define BGND_LIGHT_PINK_213 "\033[48;5;213m"
#define BGND_LIGHT_PINK_218 "\033[48;5;218m"
#define BGND_LIGHT_PINK_219 "\033[48;5;219m"

//Gray
#define BGND_BLACK_16 "\033[48;5;16m"
#define BGND_BLACK_232 "\033[48;5;232m"

#define BGND_DARK_GRAY_59 "\033[48;5;59m"
#define BGND_DARK_GRAY_233 "\033[48;5;233m"
#define BGND_DARK_GRAY_234 "\033[48;5;234m"
#define BGND_DARK_GRAY_235 "\033[48;5;235m"
#define BGND_DARK_GRAY_236 "\033[48;5;236m"
#define BGND_DARK_GRAY_237 "\033[48;5;237m"
#define BGND_DARK_GRAY_238 "\033[48;5;238m"
#define BGND_DARK_GRAY_239 "\033[48;5;239m"

#define BGND_GRAY_8 "\033[48;5;8m"
#define BGND_GRAY_240 "\033[48;5;240m"
#define BGND_GRAY_241 "\033[48;5;241m"
#define BGND_GRAY_242 "\033[48;5;242m"
#define BGND_GRAY_243 "\033[48;5;243m"
#define BGND_GRAY_244 "\033[48;5;244m"
#define BGND_GRAY_245 "\033[48;5;245m"

#define BGND_LIGHT_GRAY_246 "\033[48;5;246m"
#define BGND_LIGHT_GRAY_247 "\033[48;5;247m"
#define BGND_LIGHT_GRAY_248 "\033[48;5;248m"
#define BGND_LIGHT_GRAY_249 "\033[48;5;249m"
#define BGND_LIGHT_GRAY_250 "\033[48;5;250m"
#define BGND_LIGHT_GRAY_251 "\033[48;5;251m"
#define BGND_LIGHT_GRAY_252 "\033[48;5;252m"
#define BGND_LIGHT_GRAY_263 "\033[48;5;263m"

#define BGND_WHITE_7 "\033[48;5;7m"
#define BGND_WHITE_15 "\033[48;5;15m"
#define BGND_WHITE_194 "\033[48;5;194m"
#define BGND_WHITE_195 "\033[48;5;195m"
#define BGND_WHITE_230 "\033[48;5;230m"
#define BGND_WHITE_231 "\033[48;5;231m"
#define BGND_WHITE_254 "\033[48;5;254m"
#define BGND_WHITE_255 "\033[48;5;255m"


//          Text Color
//Red
#define TXT_DARK_RED_52 "\033[38;5;52m"
#define TXT_DARK_RED_88 "\033[38;5;88m"
#define TXT_DARK_RED_1 "\033[38;5;1m"

#define TXT_RED_124 "\033[38;5;124m"
#define TXT_RED_160 "\033[38;5;160m"
#define TXT_RED_196 "\033[38;5;196m"

#define TXT_LIGHT_RED_9 "\033[38;5;9m"

//Green
#define TXT_DARK_GREEN_22 "\033[38;5;22m"
#define TXT_DARK_GREEN_28 "\033[38;5;28m"

#define TXT_GREEN_2 "\033[38;5;2m"
#define TXT_GREEN_10 "\033[38;5;10m"
#define TXT_GREEN_34 "\033[38;5;34m"
#define TXT_GREEN_40 "\033[38;5;40m"
#define TXT_GREEN_64 "\033[38;5;64m"
#define TXT_GREEN_70 "\033[38;5;70m"
#define TXT_GREEN_76 "\033[38;5;76m"
#define TXT_GREEN_112 "\033[38;5;112m"
#define TXT_GREEN_118 "\033[38;5;118m"

#define TXT_LIGHT_GREEN_46 "\033[38;5;46m"
#define TXT_LIGHT_GREEN_47 "\033[38;5;47m"
#define TXT_LIGHT_GREEN_77 "\033[38;5;77m"
#define TXT_LIGHT_GREEN_82 "\033[38;5;82m"
#define TXT_LIGHT_GREEN_119 "\033[38;5;119m"

//Blue
#define TXT_DARK_BLUE_17 "\033[38;5;17m"
#define TXT_DARK_BLUE_18 "\033[38;5;18m"

#define TXT_BLUE_4 "\033[38;5;4m"
#define TXT_BLUE_12 "\033[38;5;12m"
#define TXT_BLUE_19 "\033[38;5;19m"
#define TXT_BLUE_20 "\033[38;5;20m"
#define TXT_BLUE_21 "\033[38;5;21m"
#define TXT_BLUE_25 "\033[38;5;25m"
#define TXT_BLUE_26 "\033[38;5;26m"
#define TXT_BLUE_27 "\033[38;5;27m"
#define TXT_BLUE_56 "\033[38;5;56m"
#define TXT_BLUE_57 "\033[38;5;57m"
#define TXT_BLUE_63 "\033[38;5;63m"

#define TXT_LIGHT_BLUE_6 "\033[38;5;6m"
#define TXT_LIGHT_BLUE_14 "\033[38;5;14m"
#define TXT_LIGHT_BLUE_32 "\033[38;5;32m"
#define TXT_LIGHT_BLUE_33 "\033[38;5;33m"
#define TXT_LIGHT_BLUE_38 "\033[38;5;38m"
#define TXT_LIGHT_BLUE_39 "\033[38;5;39m"
#define TXT_LIGHT_BLUE_44 "\033[38;5;44m"
#define TXT_LIGHT_BLUE_45 "\033[38;5;45m"
#define TXT_LIGHT_BLUE_50 "\033[38;5;50m"
#define TXT_LIGHT_BLUE_51 "\033[38;5;51m"
#define TXT_LIGHT_BLUE_68 "\033[38;5;68m"
#define TXT_LIGHT_BLUE_69 "\033[38;5;69m"
#define TXT_LIGHT_BLUE_74 "\033[38;5;74m"
#define TXT_LIGHT_BLUE_75 "\033[38;5;75m"
#define TXT_LIGHT_BLUE_80 "\033[38;5;80m"
#define TXT_LIGHT_BLUE_81 "\033[38;5;81m"
#define TXT_LIGHT_BLUE_86 "\033[38;5;86m"
#define TXT_LIGHT_BLUE_87 "\033[38;5;87m"

//Yellow
#define TXT_DARK_YELLOW_3 "\033[38;5;3m"
#define TXT_DARK_YELLOW_58 "\033[38;5;58m"
#define TXT_DARK_YELLOW_100 "\033[38;5;100m"
#define TXT_DARK_YELLOW_106 "\033[38;5;106m"
#define TXT_DARK_YELLOW_142 "\033[38;5;142m"

#define TXT_YELLOW_148 "\033[38;5;148m"
#define TXT_YELLOW_154 "\033[38;5;154m"
#define TXT_YELLOW_184 "\033[38;5;184m"
#define TXT_YELLOW_190 "\033[38;5;190m"
#define TXT_YELLOW_220 "\033[38;5;220m"
#define TXT_YELLOW_226 "\033[38;5;226m"

#define TXT_LIGHT_YELLOW_149 "\033[38;5;149m"
#define TXT_LIGHT_YELLOW_150 "\033[38;5;150m"
#define TXT_LIGHT_YELLOW_155 "\033[38;5;155m"
#define TXT_LIGHT_YELLOW_156 "\033[38;5;156m"
#define TXT_LIGHT_YELLOW_185 "\033[38;5;185m"
#define TXT_LIGHT_YELLOW_186 "\033[38;5;186m"
#define TXT_LIGHT_YELLOW_191 "\033[38;5;191m"
#define TXT_LIGHT_YELLOW_192 "\033[38;5;192m"
#define TXT_LIGHT_YELLOW_221 "\033[38;5;221m"
#define TXT_LIGHT_YELLOW_222 "\033[38;5;222m"
#define TXT_LIGHT_YELLOW_227 "\033[38;5;227m"
#define TXT_LIGHT_YELLOW_228 "\033[38;5;228m"

//Orange
#define TXT_ORANGE_130 "\033[38;5;130m"
#define TXT_ORANGE_166 "\033[38;5;166m"
#define TXT_ORANGE_172 "\033[38;5;172m"
#define TXT_ORANGE_202 "\033[38;5;202m"
#define TXT_ORANGE_208 "\033[38;5;130m"
#define TXT_ORANGE_214 "\033[38;5;214m"

//Brown
#define TXT_BROWN_94 "\033[38;5;94m"
#define TXT_BROWN_136 "\033[38;5;136m"
#define TXT_BROWN_137 "\033[38;5;137m"

//Aqua
#define TXT_DARK_AQUA_23 "\033[38;5;23m"
#define TXT_DARK_AQUA_24 "\033[38;5;24m"
#define TXT_DARK_AQUA_29 "\033[38;5;29m"
#define TXT_DARK_AQUA_30 "\033[38;5;30m"
#define TXT_DARK_AQUA_31 "\033[38;5;31m"
#define TXT_DARK_AQUA_65 "\033[38;5;65m"
#define TXT_DARK_AQUA_66 "\033[38;5;66m"
#define TXT_DARK_AQUA_67 "\033[38;5;67m"

#define TXT_AQUA_35 "\033[38;5;35m"
#define TXT_AQUA_36 "\033[38;5;36m"
#define TXT_AQUA_37 "\033[38;5;37m"
#define TXT_AQUA_71 "\033[38;5;71m"
#define TXT_AQUA_78 "\033[38;5;78m"
#define TXT_AQUA_83 "\033[38;5;83m"
#define TXT_AQUA_113 "\033[38;5;113m"
#define TXT_AQUA_119 "\033[38;5;119m"

#define TXT_LIGHT_AQUA_41 "\033[38;5;41m"
#define TXT_LIGHT_AQUA_42 "\033[38;5;42m"
#define TXT_LIGHT_AQUA_43 "\033[38;5;43m"
#define TXT_LIGHT_AQUA_48 "\033[38;5;48m"
#define TXT_LIGHT_AQUA_49 "\033[38;5;49m"
#define TXT_LIGHT_AQUA_72 "\033[38;5;72m"
#define TXT_LIGHT_AQUA_73 "\033[38;5;73m"
#define TXT_LIGHT_AQUA_79 "\033[38;5;79m"
#define TXT_LIGHT_AQUA_84 "\033[38;5;84m"
#define TXT_LIGHT_AQUA_85 "\033[38;5;85m"
#define TXT_LIGHT_AQUA_114 "\033[38;5;114m"
#define TXT_LIGHT_AQUA_120 "\033[38;5;120m"
#define TXT_LIGHT_AQUA_121 "\033[38;5;121m"
#define TXT_LIGHT_AQUA_122 "\033[38;5;122m"
#define TXT_LIGHT_AQUA_123 "\033[38;5;123m"

//Purple
#define TXT_DARK_PURPLE_53 "\033[38;5;53m"
#define TXT_DARK_PURPLE_54 "\033[38;5;54m"
#define TXT_DARK_PURPLE_55 "\033[38;5;55m"
#define TXT_DARK_PURPLE_89 "\033[38;5;89m"
#define TXT_DARK_PURPLE_90 "\033[38;5;90m"
#define TXT_DARK_PURPLE_96 "\033[38;5;96m"
#define TXT_DARK_PURPLE_125 "\033[38;5;125m"
#define TXT_DARK_PURPLE_126 "\033[38;5;126m"
#define TXT_DARK_PURPLE_127 "\033[38;5;127m"

#define TXT_PURPLE_5 "\033[38;5;5m"
#define TXT_PURPLE_13 "\033[38;5;13m"
#define TXT_PURPLE_91 "\033[38;5;91m"
#define TXT_PURPLE_92 "\033[38;5;92m"
#define TXT_PURPLE_93 "\033[38;5;93m"
#define TXT_PURPLE_97 "\033[38;5;97m"
#define TXT_PURPLE_98 "\033[38;5;98m"
#define TXT_PURPLE_99 "\033[38;5;99m"
#define TXT_PURPLE_128 "\033[38;5;128m"
#define TXT_PURPLE_129 "\033[38;5;129m"

#define TXT_LIGHT_PURPLE_104 "\033[38;5;104m"
#define TXT_LIGHT_PURPLE_105 "\033[38;5;105m"
#define TXT_LIGHT_PURPLE_133 "\033[38;5;133m"
#define TXT_LIGHT_PURPLE_134 "\033[38;5;134m"
#define TXT_LIGHT_PURPLE_135 "\033[38;5;135m"
#define TXT_LIGHT_PURPLE_140 "\033[38;5;140m"
#define TXT_LIGHT_PURPLE_141 "\033[38;5;141m"
#define TXT_LIGHT_PURPLE_164 "\033[38;5;164m"
#define TXT_LIGHT_PURPLE_165 "\033[38;5;165m"
#define TXT_LIGHT_PURPLE_170 "\033[38;5;170m"
#define TXT_LIGHT_PURPLE_171 "\033[38;5;171m"
#define TXT_LIGHT_PURPLE_176 "\033[38;5;176m"
#define TXT_LIGHT_PURPLE_177 "\033[38;5;177m"

//Pink
#define TXT_DARK_PINK_131 "\033[38;5;131m"
#define TXT_DARK_PINK_132 "\033[38;5;132m"
#define TXT_DARK_PINK_174 "\033[38;5;174m"

#define TXT_PINK_161 "\033[38;5;161m"
#define TXT_PINK_162 "\033[38;5;162m"
#define TXT_PINK_163 "\033[38;5;163m"
#define TXT_PINK_197 "\033[38;5;197m"
#define TXT_PINK_198 "\033[38;5;198m"
#define TXT_PINK_199 "\033[38;5;199m"
#define TXT_PINK_200 "\033[38;5;200m"
#define TXT_PINK_201 "\033[38;5;201m"

#define TXT_LIGHT_PINK_167 "\033[38;5;167m"
#define TXT_LIGHT_PINK_168 "\033[38;5;168m"
#define TXT_LIGHT_PINK_169 "\033[38;5;169m"
#define TXT_LIGHT_PINK_203 "\033[38;5;203m"
#define TXT_LIGHT_PINK_204 "\033[38;5;204m"
#define TXT_LIGHT_PINK_205 "\033[38;5;205m"
#define TXT_LIGHT_PINK_206 "\033[38;5;206m"
#define TXT_LIGHT_PINK_207 "\033[38;5;207m"
#define TXT_LIGHT_PINK_209 "\033[38;5;209m"
#define TXT_LIGHT_PINK_210 "\033[38;5;210m"
#define TXT_LIGHT_PINK_211 "\033[38;5;211m"
#define TXT_LIGHT_PINK_212 "\033[38;5;212m"
#define TXT_LIGHT_PINK_213 "\033[38;5;213m"
#define TXT_LIGHT_PINK_218 "\033[38;5;218m"
#define TXT_LIGHT_PINK_219 "\033[38;5;219m"

//Gray
#define TXT_BLACK_16 "\033[38;5;16m"
#define TXT_BLACK_232 "\033[38;5;232m"

#define TXT_DARK_GRAY_59 "\033[38;5;59m"
#define TXT_DARK_GRAY_233 "\033[38;5;233m"
#define TXT_DARK_GRAY_234 "\033[38;5;234m"
#define TXT_DARK_GRAY_235 "\033[38;5;235m"
#define TXT_DARK_GRAY_236 "\033[38;5;236m"
#define TXT_DARK_GRAY_237 "\033[38;5;237m"
#define TXT_DARK_GRAY_238 "\033[38;5;238m"
#define TXT_DARK_GRAY_239 "\033[38;5;239m"

#define TXT_GRAY_8 "\033[38;5;8m"
#define TXT_GRAY_240 "\033[38;5;240m"
#define TXT_GRAY_241 "\033[38;5;241m"
#define TXT_GRAY_242 "\033[38;5;242m"
#define TXT_GRAY_243 "\033[38;5;243m"
#define TXT_GRAY_244 "\033[38;5;244m"
#define TXT_GRAY_245 "\033[38;5;245m"

#define TXT_LIGHT_GRAY_246 "\033[38;5;246m"
#define TXT_LIGHT_GRAY_247 "\033[38;5;247m"
#define TXT_LIGHT_GRAY_248 "\033[38;5;248m"
#define TXT_LIGHT_GRAY_249 "\033[38;5;249m"
#define TXT_LIGHT_GRAY_250 "\033[38;5;250m"
#define TXT_LIGHT_GRAY_251 "\033[38;5;251m"
#define TXT_LIGHT_GRAY_252 "\033[38;5;252m"
#define TXT_LIGHT_GRAY_263 "\033[38;5;263m"

#define TXT_WHITE_7 "\033[38;5;7m"
#define TXT_WHITE_15 "\033[38;5;15m"
#define TXT_WHITE_194 "\033[38;5;194m"
#define TXT_WHITE_195 "\033[38;5;195m"
#define TXT_WHITE_230 "\033[38;5;230m"
#define TXT_WHITE_231 "\033[38;5;231m"
#define TXT_WHITE_254 "\033[38;5;254m"
#define TXT_WHITE_255 "\033[38;5;255m"

#endif //__COLORS__