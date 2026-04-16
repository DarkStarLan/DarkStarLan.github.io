// 粒子背景特效
(function() {
    const canvas = document.getElementById('bg-canvas');
    if (!canvas) return;

    const ctx = canvas.getContext('2d');
    let particles = [];
    let mousePosition = { x: null, y: null };

    // 设置画布尺寸
    function resizeCanvas() {
        canvas.width = window.innerWidth;
        canvas.height = window.innerHeight;
    }

    resizeCanvas();
    window.addEventListener('resize', resizeCanvas);

    // 粒子类
    class Particle {
        constructor() {
            this.x = Math.random() * canvas.width;
            this.y = Math.random() * canvas.height;
            this.vx = (Math.random() - 0.5) * 0.5;
            this.vy = (Math.random() - 0.5) * 0.5;
            this.radius = Math.random() * 2 + 1;

            // 随机颜色（青色系为主）
            const colors = [
                { r: 0, g: 198, b: 198 },      // 青色
                { r: 127, g: 255, b: 212 },    // 水绿色
                { r: 102, g: 126, b: 234 },    // 紫蓝色
                { r: 252, g: 161, b: 82 },     // 橙色
            ];
            const color = colors[Math.floor(Math.random() * colors.length)];
            this.color = `rgba(${color.r}, ${color.g}, ${color.b}, 0.6)`;
        }

        update() {
            // 边界检测
            if (this.x < 0 || this.x > canvas.width) this.vx = -this.vx;
            if (this.y < 0 || this.y > canvas.height) this.vy = -this.vy;

            // 鼠标交互
            if (mousePosition.x !== null && mousePosition.y !== null) {
                const dx = mousePosition.x - this.x;
                const dy = mousePosition.y - this.y;
                const distance = Math.sqrt(dx * dx + dy * dy);

                if (distance < 150) {
                    const force = (150 - distance) / 150;
                    this.vx -= (dx / distance) * force * 0.2;
                    this.vy -= (dy / distance) * force * 0.2;
                }
            }

            // 速度衰减
            this.vx *= 0.99;
            this.vy *= 0.99;

            // 更新位置
            this.x += this.vx;
            this.y += this.vy;
        }

        draw() {
            ctx.beginPath();
            ctx.arc(this.x, this.y, this.radius, 0, Math.PI * 2);
            ctx.fillStyle = this.color;
            ctx.fill();
        }
    }

    // 创建粒子
    function createParticles() {
        const particleCount = Math.min(Math.floor((canvas.width * canvas.height) / 8000), 150);
        particles = [];
        for (let i = 0; i < particleCount; i++) {
            particles.push(new Particle());
        }
    }

    // 连接粒子
    function connectParticles() {
        for (let i = 0; i < particles.length; i++) {
            for (let j = i + 1; j < particles.length; j++) {
                const dx = particles[i].x - particles[j].x;
                const dy = particles[i].y - particles[j].y;
                const distance = Math.sqrt(dx * dx + dy * dy);

                if (distance < 120) {
                    ctx.beginPath();
                    ctx.strokeStyle = `rgba(0, 198, 198, ${0.2 * (1 - distance / 120)})`;
                    ctx.lineWidth = 0.5;
                    ctx.moveTo(particles[i].x, particles[i].y);
                    ctx.lineTo(particles[j].x, particles[j].y);
                    ctx.stroke();
                }
            }
        }
    }

    // 动画循环
    function animate() {
        ctx.clearRect(0, 0, canvas.width, canvas.height);

        particles.forEach(particle => {
            particle.update();
            particle.draw();
        });

        connectParticles();
        requestAnimationFrame(animate);
    }

    // 鼠标移动事件
    document.addEventListener('mousemove', (e) => {
        mousePosition.x = e.clientX;
        mousePosition.y = e.clientY;
    });

    document.addEventListener('mouseleave', () => {
        mousePosition.x = null;
        mousePosition.y = null;
    });

    // 初始化
    createParticles();
    animate();

    // 窗口大小改变时重新创建粒子
    window.addEventListener('resize', () => {
        createParticles();
    });
})();
