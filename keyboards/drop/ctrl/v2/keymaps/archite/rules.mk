CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
KEYBOARD_SHARED_EP = yes
LEADER_ENABLE = yes

SRC += utility.c

ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards
endif

ifeq ($(strip $(LEADER_ENABLE)), yes)
	SRC += features/leader.c
endif

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += features/rgb/rgb_matrix_user.c
endif
