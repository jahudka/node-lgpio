const os = require('os');
const { execSync } = require('child_process');

if (os.platform() === 'linux') {
  execSync('node-gyp rebuild', {
    stdio: 'inherit'
  });
}
