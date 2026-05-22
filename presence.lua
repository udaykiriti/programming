return {
  "vyfor/cord.nvim",
  build = ":Cord update",
  event = "VeryLazy",
  opts = {
    user_id = nil,
    log_level = "error",
    update_interval = 750,
    background_cycle = true,

    -- Display & Presentation Settings
    display = {
      theme = "catppuccin", -- Icon theme
      flavor = "dark", -- Theme flavor ('dark', 'light', 'accent')
      view = "full", -- 'full' shows both large and small icons
      swap_fields = true, -- Puts workspace name BEFORE filename on your profile
      swap_icons = false, -- Set to true to make the editor icon the large one instead
    },

    -- Advanced Idle/AFK Customization
    idle = {
      enabled = true,
      timeout = 300000, -- 5 minutes (in milliseconds)
      show_status = true, -- Still show you are in Neovim when AFK
      ignore_focus = true, -- Keeps idle status even if Nvim window is focused
      unidle_on_focus = true, -- Wakes up status immediately upon clicking into Neovim
      details = function()
        return "[ z Z z ] disconnected"
      end,
      state = function()
        return "<- IDLE ->"
      end,
      tooltip = function()
        return "(-_-)zzZ"
      end,
    },

    -- Context-Aware Text Customizations
    text = {
      viewing = function(opts)
        return "::: inspecting » " .. opts.filename
      end,
      editing = function(opts)
        return "»» compiling » " .. opts.filename
      end,
      file_browser = function(opts)
        return "[tree] // " .. opts.name
      end,
      plugin_manager = function(opts)
        return "pkg_mgr // " .. opts.name
      end,
      workspace = function(opts)
        return "root@ " .. opts.workspace
      end,

      -- Micro ASCII and Geometric Customizations
      lsp = function(opts)
        return "lsp_srv // " .. opts.name
      end,
      diagnostics = function()
        return "[!] fixing_errs... 0xERR"
      end,
      terminal = function()
        return "sh$ ./run_process.sh"
      end,
      dashboard = function()
        return "/* ~ nvim_home ~ */"
      end,
      docs = function(opts)
        return "man_pages // " .. opts.name
      end,
    },

    -- Enhanced Discord Connection Reliability
    advanced = {
      discord = {
        reconnect = {
          enabled = true, -- Automatically re-establishes broken IPC pipes
          interval = 5000, -- Tries to find Discord every 5 seconds if disconnected
          initial = true, -- Attempts reconnection right at launch
        },
      },
    },

    -- Buttons to show on your Discord profile
    buttons = {
      {
        label = "View My Config",
        url = "https://github.com/yourusername/dotfiles",
      },
    },
  },
}
